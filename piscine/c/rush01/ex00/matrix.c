/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:53:09 by doriani           #+#    #+#             */
/*   Updated: 2023/02/28 14:02:47 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	factorial(int n);

int	is_sudoku(int dim, int **mx)
{
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			for (int z = j + 1; z < dim; z++)
				if (mx[i][j] == mx[i][z] || mx[j][i] == mx[z][i])
					return (0);
	return (1);
}

int	update_rows(int dim, int *rows)
{
	int i;
	int last;

	last = factorial(dim) - 1;
	i = dim;
	while (i > 0)
		if (rows[--i] < last)
		{
			rows[i++]++;
			while (i < dim)
				rows[i++] = 0;
			return (1);
		}
	return (0);
}

void	set_matrix(int dim, int **matrix, int **permutations, int *rows)
{
	for (int i = 0; i < dim; i++)
		matrix[i] = permutations[rows[i]];
}

int	get_next_matrix(int dim, int **mx, int **permutations, int *rows)
{
	while (update_rows(dim, rows))
	{
		set_matrix(dim, mx, permutations, rows);
		if (is_sudoku(dim, mx))
			return (1);
	}
	return (0);
}	
