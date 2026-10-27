/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:26:14 by doriani           #+#    #+#             */
/*   Updated: 2023/03/06 11:54:56 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_solution(int *solution)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = (char) solution[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_safe(int *try, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (try[i] == row
			|| try[i] == row - col + i
			|| try[i] == row + col - i)
			return (0);
		i++;
	}
	return (1);
}

void	solve_ten_queens(int *try, int col, int *solutions)
{
	int	row;

	if (col > 9)
	{
		print_solution(try);
		*solutions += 1;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (is_safe(try, col, row))
		{
			try[col] = row;
			solve_ten_queens(try, col + 1, solutions);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	try[10];
	int	solutions;

	solutions = 0;
	solve_ten_queens(try, 0, &solutions);
	return (solutions);
}
