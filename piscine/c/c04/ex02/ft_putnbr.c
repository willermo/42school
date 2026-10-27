/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:08:37 by doriani           #+#    #+#             */
/*   Updated: 2023/03/02 10:53:07 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	number[12];
	int		i;
	int		int_min_detected;

	int_min_detected = 0;
	if (nb - 1 > nb)
	{
		nb += 1;
		int_min_detected = 1;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	i = 0;
	while (nb > 9)
	{
		number[i++] = '0' + nb % 10;
		nb /= 10;
	}
	number[i] = '0' + nb;
	number[0] += int_min_detected;
	while (i >= 0)
		write(1, &number[i--], 1);
}
