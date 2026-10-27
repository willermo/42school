/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 01:23:13 by doriani           #+#    #+#             */
/*   Updated: 2023/04/16 13:05:17 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	write_pointer(unsigned long long int n, int is_upper)
{
	char	*str;
	int		len;

	if (n == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	str = ft_itoa_16(n, is_upper);
	len = ft_strlen(str);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	free(str);
	return (len + 2);
}
