/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 03:27:56 by doriani           #+#    #+#             */
/*   Updated: 2023/03/05 03:28:36 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*runner;

	runner = dest;
	while (*src)
		*runner++ = *src++;
	*runner = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	ft_char_is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_char_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f');
}

void	ft_putstring(char *str)
{
	while (*str)
		write(1, str++, 1);
}
