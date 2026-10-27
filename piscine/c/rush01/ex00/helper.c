/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:40:34 by doriani           #+#    #+#             */
/*   Updated: 2023/02/28 16:16:50 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	factorial(int n)
{
	return n < 1 ? 1 : n * factorial(n - 1);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_matrix(int dim, int **matrix)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while (i < dim)
	{
		x = i;
		y = j;
		while (x < dim)
			swap(&matrix[i][x++], &matrix[y++][j]);
		i++;
		j++;
	}
}

void	print_matrix(int **matrix, int dim)
{
	int		i;
	int		j;
	int		*row;
	char	buf;

	i = 0;
	while (i < dim)
	{
		row = matrix[i];
		j = 0;
		while (j < dim)
		{
			buf = row[j] + '0';
			write(1, &buf, 1);
			if (j < dim - 1)
				write(1, " ", 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}
