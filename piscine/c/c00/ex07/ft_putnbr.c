/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:08:37 by doriani           #+#    #+#             */
/*   Updated: 2023/02/14 17:50:39 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* array size should be set as (int)log(INT_MAX)
 * and limits.h and math.h should be included
 * but this would violate the project constraint
 * that allows only write posix function to bu used
 * so we are declaring a quite large sized array
 * to allow 32bit integer to be represented as
 *  a string made of character array.
 */

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
