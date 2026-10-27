/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:27:27 by doriani           #+#    #+#             */
/*   Updated: 2023/03/09 15:25:03 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int number)
{
	char	literal;

	literal = number + '0';
	write(1, &literal, 1);
}

void	func(int number)
{
	char	literal;

	literal = number + '0';
	write(1, &literal, 1);
}

int	ft_map(int *tab, int length, int (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		(*f)(tab[i++]);
}

int	main(void)
{
	int i;
	int	tab[5];

	i = 0;
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	tab[3] = 4;
	tab[4] = 5;
	func(tab, 5, &ft_putnbr);
	while (i < 5)
		ft_putnbr(tab[i++];
	return (0);
}
