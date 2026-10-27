/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:18:57 by doriani           #+#    #+#             */
/*   Updated: 2023/03/02 10:51:18 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (*idx == '-' || *idx == '+' || *idx <= 32)
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

int	get_index(char *ch, char *string)
{
	int	i;

	i = 0;
	while (*string)
	{
		if (*ch == *string++)
			return (i);
		i++;
	}
	return (-1);
}

int	get_base_size(char *base)
{
	int	size;

	size = 0;
	while (*base++)
		size++;
	return (size);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		result;
	int		digit;

	sign = 1;
	result = 0;
	if (is_invalid(base))
		return (0);
	while (*str == ' ' || *str == '\f' || *str == '\n' \
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && get_index(str, base) != -1)
	{
		digit = get_index(str++, base);
		if (digit >= 0)
			result = result * get_base_size(base) + digit;
	}
	result *= sign;
	return (result);
}
