/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:38:00 by doriani           #+#    #+#             */
/*   Updated: 2023/02/14 12:55:36 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	comb[3];
	char	*sep;

	sep = ", ";
	comb[0] = '0';
	while (comb[0] <= '7')
	{
		comb[1] = comb[0] + 1;
		while (comb[1] <= '8')
		{
			comb[2] = comb[1] + 1;
			while (comb[2] <= '9')
			{
				write(1, &comb, 3);
				if (!(comb[0] == '7' && comb[1] == '8' && comb[2] == '9'))
					write(1, sep, 2);
			comb[2]++;
			}
		comb[1]++;
		}
	comb[0]++;
	}	
}
