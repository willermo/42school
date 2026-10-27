/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 03:28:58 by doriani           #+#    #+#             */
/*   Updated: 2023/03/05 14:15:50 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_substr(char str[], int start, int end, int skip_zeroes)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = start;
	out = (char *) malloc((end - start + 1) * sizeof(char));
	while (j < end)
	{
		if (! skip_zeroes || (skip_zeroes && str[j] != '0'))
		{
			out[i++] = str[j++];
			skip_zeroes = 0;
		}
		else
			j++;
	}
	out[i] = '\0';
	return (out);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (ft_char_is_space(*str))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	result *= sign;
	return (result);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

int	ceil_log10(int n)
{
	int	i;

	i = 1;
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*out;
	int		size;

	size = ceil_log10(n);
	out = (char *) malloc((size + 1) * sizeof (char));
	out[size] = '\0';
	while (size > 0)
	{
		out[--size] = n % 10 + '0';
		n /= 10;
	}
	return (out);
}
