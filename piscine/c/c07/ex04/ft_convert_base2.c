/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:36:52 by doriani           #+#    #+#             */
/*   Updated: 2023/03/03 09:52:42 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char ch)
{
	if (ch == ' ' || ch == '\f' || ch == '\n' \
	|| ch == '\r' || ch == '\t' || ch == '\v')
		return (1);
	return (0);
}

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
