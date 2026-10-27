/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:14:39 by doriani           #+#    #+#             */
/*   Updated: 2023/02/14 15:31:01 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_next_digits(char *digits, int n)
{
	int	pos;

	pos = n;
	while (--pos >= 0)
	{
		if (digits[pos] < '9' - n + pos + 1)
		{
			digits[pos]++;
			while (pos++ < n)
			{
				digits[pos] = digits[pos -1] + 1;
			}
			return (1);
		}
	}
	return (0);
}

void	ft_print_combn(int n)
{
	char	digits[10];
	int		i;
	char	*sep;
	int		has_next;

	i = 0;
	while (i < n)
	{
		digits[i] = '0' + i;
		i++;
	}
	sep = ", ";
	has_next = 1;
	while (has_next)
	{
		write(1, digits, n);
		has_next = get_next_digits(digits, n);
		if (has_next)
		{
			write(1, sep, 2);
		}
	}
}
