/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:22:18 by doriani           #+#    #+#             */
/*   Updated: 2023/03/02 10:51:32 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	char_is_repeated(char *str)
{
	char	ch;

	ch = *str++;
	while (*str)
		if (ch == *str++)
			return (1);
	return (0);
}

int	is_invalid(char *base)
{
	int		len;
	int		offset;
	char	*idx;

	len = 0;
	offset = 0;
	idx = base;
	if (!base)
		return (1);
	while (*idx)
	{
		if (*idx == '-' || *idx == '+')
			return (1);
		idx++;
		len++;
	}
	if (len < 2)
		return (1);
	while (offset < len)
	{
		if (char_is_repeated(base + offset))
			return (1);
		offset++;
	}
	return (0);
}

int	get_size(char *base)
{
	int	size;

	size = 0;
	while (*base++)
		size++;
	return (size);
}

int	modulo(int dividendo, int divisore)
{
	int	mod;

	mod = dividendo % divisore;
	if (mod < 0)
		mod *= -1;
	return (mod);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		size;
	char	converted[32];
	int		i;

	i = 0;
	if (is_invalid(base))
		return ;
	size = get_size(base);
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	if (nbr < 0)
		write(1, "-", 1);
	while (nbr != 0)
	{
		converted[i++] = base[modulo(nbr, size)];
		nbr /= size;
	}
	i--;
	while (i >= 0)
		write(1, &converted[i--], 1);
}
