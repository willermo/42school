/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:54:32 by doriani           #+#    #+#             */
/*   Updated: 2023/02/23 00:06:03 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	deep_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	return (nb * deep_recursive_power(nb, power -1));
}

int	ft_recursive_power(int nb, int power)
{
	if (nb == 0 && power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (deep_recursive_power(nb, power));
}
