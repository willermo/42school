/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:31:57 by doriani           #+#    #+#             */
/*   Updated: 2023/02/22 23:41:30 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	deep_recursive_factorial(int nb)
{
	if (nb <= 0)
		return (1);
	return (nb * deep_recursive_factorial(nb - 1));
}

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	return (deep_recursive_factorial(nb));
}
