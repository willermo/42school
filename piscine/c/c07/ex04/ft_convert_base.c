/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:30:47 by doriani           #+#    #+#             */
/*   Updated: 2023/03/07 22:41:57 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	ft_isspace(char ch);
int	is_invalid(char *base);
int	get_index(char *ch, char *string);
int	get_base_size(char *base);

int	fits_into_int_range(long long number, int sign)
{
	if (sign == 1)
		return (number < INT_MAX);
	return (-number > INT_MIN);
}

long long	convert_from_base(char *nbr, char *base_from)
{
	long long	result;
	int			digit;
	int			base_size;

	result = 0;
	base_size = get_base_size(base_from);
	while (*nbr && get_index(nbr, base_from) != -1)
	{
		digit = get_index(nbr++, base_from);
		result = result * base_size + digit;
	}
	return (result);
}

char	*convert_to_base(int number, char *base_to, int is_negative)
{
	char	*result;
	int		base_size;
	int		num_size;
	int		copy;

	copy = number;
	base_size = get_base_size(base_to);
	num_size = 1 + is_negative;
	while (copy / base_size)
	{
		num_size++;
		copy /= base_size;
	}
	result = (char *) malloc((num_size + 1) * sizeof(char));
	result[num_size] = '\0';
	while (number / base_size)
	{
		result[--num_size] = base_to[number % base_size];
		number /= base_size;
	}
	result[--num_size] = base_to[number % base_size];
	if (is_negative)
		result[--num_size] = '-';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*converted;
	long long		result;
	int				sign;
	int				is_negative;

	sign = 1;
	result = 0;
	is_negative = 0;
	if (is_invalid(base_from) || is_invalid(base_to))
		return (NULL);
	while (ft_isspace(*nbr))
		nbr++;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	result = convert_from_base(nbr, base_from);
	if (! fits_into_int_range(result, sign))
		return (0);
	if (sign < 1 && result != 0)
		is_negative = 1;
	converted = convert_to_base((int) result, base_to, is_negative);
	return (converted);
}
