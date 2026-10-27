/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 00:46:29 by doriani           #+#    #+#             */
/*   Updated: 2023/03/02 19:06:04 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Do we have to equate to 0 complex numbers too?
// Complex numbers are not irrational. How to handle them?
// Return 0? Return an error? As for now, we'll return 0...
int	ft_sqrt(int nb)
{
	unsigned int	i;
	unsigned int	result;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	i = 1;
	result = 1;
	while (result < (unsigned int) nb)
	{
		i++;
		result = i * i;
	}
	if ((i * i) == (unsigned int) nb)
		return ((int) i);
	return (0);
}
