/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:56:01 by doriani           #+#    #+#             */
/*   Updated: 2023/02/28 19:57:05 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	factorial(int n);

int	has_digit(int dim, int *permutation, int digit)
{
	for (int i = 0; i < dim; i++)
		if (permutation[i] == digit)
			return (1);
	return (0);
}

int	is_valid_permutation(int dim, int *p)
{
	for (int i = 1; i <= dim; i++)
		if (! has_digit(dim, p, i))
				return(0);
	return (1);
}

void	add_permutation(int dim, int **address, int *perm)
{
	int	i;
	int	*p;

	i = 0;
	p = (int *) malloc(dim * sizeof(int));
	while (i < dim)
	{
		p[i] = perm[i];
		i++;
	}
	*address = p;
}

void	update_p(int dim, int *p)
{
	int i;

	i = dim;
	while (i > 0)
		if (p[--i] < dim)
		{
			p[i++]++;
			while(i < dim)
				p[i++] = 1;
			return ;
		}
}

int	**get_permutations(int dim)
{
	int	**permutations;
	int	p[dim];
	int	size;
	int	i;

	size = factorial(dim);
	for (i = 0; i < dim; i++)
		p[i] = i + 1;
	permutations = (int **) malloc(size * sizeof(int *));
	i = 0;
	while (i < size)
	{
		if (is_valid_permutation(dim, p))
			add_permutation(dim, &permutations[i++], p);
		update_p(dim, p);
	}
	return (permutations);
}
