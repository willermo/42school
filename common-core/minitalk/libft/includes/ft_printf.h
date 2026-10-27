/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:10:56 by doriani           #+#    #+#             */
/*   Updated: 2023/04/14 12:33:23 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>

int	ft_printf(const char *str, ...);
int	write_char(int c);
int	write_string(char *str);
int	write_pointer(unsigned long long int n, int is_upper);
int	write_decimal(int n);
int	write_integer(int n);
int	write_unsigned(unsigned int n);
int	write_hex(unsigned int n, int is_upper);
int	write_percent(void);
int	write_octal(unsigned int n);
#endif
