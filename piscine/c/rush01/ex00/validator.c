/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:39:11 by doriani           #+#    #+#             */
/*   Updated: 2023/02/28 17:00:19 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_matrix(int dim, int **matrix);

int	visible_left_boxes(int dim, int *row)
{
	int	visibles;
	int	max;
	int	i;

	visibles = 1;
	i = 0;
	max = row[i++];
	while (i < dim)
	{
		if (row[i] > max)
		{
			max = row[i];
			visibles++;
		}
		i++;
	}
	return (visibles);
}

int	visible_right_boxes(int dim, int *row)
{
	int	visibles;
	int	max;
	int	i;

	visibles = 1;
	i = dim;
	max = row[--i];
	while (i > 0)
		if (row[--i] > max)
		{
			max = row[i];
			visibles++;
		}
	return (visibles);
}

int	row_is_valid(int dim, int *row, int left, int right)
{
	if (left != visible_left_boxes(dim, row))
		return (0);
	if (right != visible_right_boxes(dim,  row))
		return (0);
	return (1);
}

int	is_correct(int dim, int **permutation, int *rules)
{
	int	*row;
	int	line;

	line = 0;
	while (line < dim)
	{
		row = permutation[line];
		if (! row_is_valid(dim, row, rules[dim * 2 + line], rules[dim * 3 + line]))
			return (0);
		line++;
	}
	swap_matrix(dim, permutation);
	line = 0;
	while (line < dim)
	{
		row = permutation[line];
		if (! row_is_valid(dim, row, rules[0 + line], rules[dim + line]))
		{
			swap_matrix(dim, permutation);
			return (0);
		}
		line++;
	}
	swap_matrix(dim, permutation);
	return (1);
}
