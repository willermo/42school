/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:58:06 by doriani           #+#    #+#             */
/*   Updated: 2023/03/01 17:20:10 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	set_value(unsigned char *addr, unsigned char value)
{
	if (value < 10)
		*addr = value + '0';
	else
		*addr = value - 10 + 'a';
}

unsigned char	*hex_value(unsigned char *c, unsigned char *code)
{
	set_value(code + 2, *c % 16);
	set_value(code + 1, *c / 16);
	return (code);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	code[3];

	code[0] = '\\';
	while (*str)
	{
		if (*str >= 32 && *str <= 126)
			write(1, str, 1);
		else
			write(1, hex_value((unsigned char *)str, code), 3);
		str++;
	}
}
