/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 10:05:39 by doriani           #+#    #+#             */
/*   Updated: 2023/03/05 12:42:56 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*value_of(t_dict *dict, char *key)
{
	while (dict)
	{
		if (!ft_strcmp(dict -> key, key))
			return (dict -> value);
	dict = dict -> next;
	}
	return (0);
}

void	print_key(t_dict *dict, int number)
{
	char	*literal;

	literal = ft_itoa(number);
	ft_putstring(value_of(dict, literal));
	free(literal);
}

void	print_0_19(t_dict *dict, int number)
{
	print_key(dict, number);
	ft_putstring(" ");
}

void	print_20_99(t_dict *dict, int number)
{
	print_key(dict, number / 10 * 10);
	if (number % 10)
	{
		ft_putstring("-");
		print_key(dict, number % 10);
	}
	ft_putstring(" ");
}

void	print_100_999(t_dict *dict, int number)
{
	if (number == 100)
	{
		print_key(dict, 1);
		ft_putstring(" ");
		print_key(dict, number);
		ft_putstring(" ");
	}
	else if (number % 100 == 0)
	{
		print_key(dict, number / 100);
		ft_putstring(" ");
		print_key(dict, 100);
		ft_putstring(" ");
	}
	else
	{
		print_key(dict, number / 100);
		ft_putstring(" ");
		print_key(dict, 100);
		ft_putstring(" and ");
		if (number % 100 > 19)
			print_20_99(dict, number % 100);
		else
			print_0_19(dict, number % 100);
	}
}
