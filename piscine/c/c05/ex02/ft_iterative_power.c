/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:41:59 by doriani           #+#    #+#             */
/*   Updated: 2023/02/22 23:54:04 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	result = 1;
	while (power > 0)
	{
		result *= nb;
		power --;
	}
	return (result);
}
