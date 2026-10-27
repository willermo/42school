/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssahu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:43:27 by ssahu             #+#    #+#             */
/*   Updated: 2023/02/18 16:43:56 by ssahu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *c, int len);

void	draw_first_row(int x, char *a, char *b)
{
	int		i;

	i = 1;
	ft_putchar(a, 1);
	while (i < x -1)
	{
		ft_putchar("B", 1);
		i++;
	}
	ft_putchar(b, 1);
	ft_putchar("\n", 1);
}

void	draw_y(int y, int x)
{
	int		i;
	int		j;

	i = 1;
	while (i < y - 1)
	{
		j = 1;
		ft_putchar("B", 1);
		if (x > 2)
		{
			while (j < x -1)
			{
				ft_putchar(" ", 1);
				j++;
			}
			ft_putchar("B", 1);
		}
		else if (x == 2)
			ft_putchar("B", 1);
		ft_putchar("\n", 1);
		i++;
	}
}

void	draw_last_row(int x)
{
	if (x > 2)
		draw_first_row(x, "C", "A");
	else if (x == 2)
	{
		ft_putchar("CA\n", 3);
	}
	else
	{
		ft_putchar("C", 1);
		ft_putchar("\n", 1);
	}
}

int	check_input(int x, int y)
{
	char	*error;

	error = "I dati inseriti non sono validi.\n";
	if (x <= 0 || y <= 0)
	{
		write(1, error, 33);
		return (1);
	}
	return (0);
}

void	rush(int x, int y)
{
	if (check_input(x, y))
		return ;
	if (x > 2)
		draw_first_row(x, "A", "C");
	else if (x == 2)
		ft_putchar("AC\n", 3);
	else
	{
		ft_putchar("A\n", 2);
	}
	if (y > 2)
		draw_y(y, x);
	else if (y == 2)
	{
		draw_last_row(x);
		return ;
	}
	else if (y == 1)
		return ;
	draw_last_row(x);
	return ;
}
