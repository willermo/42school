/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 01:37:29 by doriani           #+#    #+#             */
/*   Updated: 2023/03/05 14:30:57 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_little_value(t_dict *dict, char *value, int start, int end)
{
	char	*literal;
	int		number;

	literal = ft_substr(value, start, end, 0);
	number = ft_atoi(literal);
	if (number == 0 && ft_strlen(literal) > 1)
	{
		free(literal);
		return ;
	}
	ft_putstring(" ");
	if (number < 20)
		print_0_19(dict, number);
	else if (number < 100)
		print_20_99(dict, number);
	else
		print_100_999(dict, number);
	free(literal);
}

void	print_big_value(t_dict *dict, int start, int end)
{
	int		i;
	char	big[255];

	i = 0;
	big[i++] = '1';
	while (start < end)
	{
		big[i++] = '0';
		start++;
	}
	big[i] = '\0';
	ft_putstring(value_of(dict, big));
}

void	print_number(t_dict *dict, char *number)
{
	int		n_len;
	int		grouped_thousands;
	int		i;
	int		mid;
	char	*new_number;

	i = 1;
	n_len = ft_strlen(number);
	grouped_thousands = 0;
	while (n_len > 3 * i++)
		grouped_thousands++;
	mid = n_len - grouped_thousands * 3;
	print_little_value(dict, number, 0, mid);
	if (grouped_thousands)
	{
		print_big_value(dict, mid, n_len);
		new_number = ft_substr(number, mid, n_len, 1);
		if (ft_atoi(new_number) == 0)
			return ;
		ft_putstring(",");
		print_number(dict, new_number);
		free(new_number);
	}
}
