/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:10:47 by doriani           #+#    #+#             */
/*   Updated: 2023/04/14 14:29:16 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_argument(va_list vargs, const char fmt)
{
	int		len;

	len = 0;
	if (fmt == 'c')
		len += write_char(va_arg(vargs, int));
	else if (fmt == 's')
		len += write_string(va_arg(vargs, char *));
	else if (fmt == 'p')
		len += write_pointer(va_arg(vargs, unsigned long long int), 0);
	else if (fmt == 'd')
		len += write_decimal(va_arg(vargs, int));
	else if (fmt == 'i')
		len += write_integer(va_arg(vargs, int));
	else if (fmt == 'u')
		len += write_unsigned(va_arg(vargs, unsigned int));
	else if (fmt == 'x' || fmt == 'X')
		len += write_hex(va_arg(vargs, unsigned int), fmt == 'X');
	else if (fmt == '%')
		len += write_percent();
	else if (fmt == 'o')
		len += write_octal(va_arg(vargs, unsigned int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	vargs;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(vargs, str);
	while (str && str[i])
	{
		if (str[i] == '%')
			len += convert_argument(vargs, str[++i]);
		else
			len += write_char(str[i]);
		i++;
	}
	va_end(vargs);
	return (len);
}
