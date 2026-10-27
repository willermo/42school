/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:35:55 by doriani           #+#    #+#             */
/*   Updated: 2023/03/05 19:38:33 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_char_is_printable(char c)
{
	return (c >= 33 && c <= 126);
}

int	validate_line(char *line)
{
	if (! ft_char_is_numeric(*line++))
		return (0);
	while (*line && ! ft_char_is_space(*line) && *line != ':')
		if (ft_char_is_printable(*line))
			line++;
	while (*line && ft_char_is_space(*line))
		line++;
	if (*line != ':')
		return (0);
	line++;
	while (*line && ft_char_is_space(*line))
		line++;
	if (*line == '\n')
		return (0);
	return (1);
}

int	validate_dictionary(t_file dict_file)
{
	char	line[255];

	while (readline(dict_file, line))
	{
		if (! validate_line(line))
			return (0);
	}
	return (1);
}

int	get_max_dict_value(t_dict *dict)
{
	int		max;
	int		key_len;

	max = 0;
	while (dict)
	{
		key_len = ft_strlen(dict -> key);
		if (key_len > max)
			max = key_len;
		dict = dict -> next;
	}
	return (max);
}

int	validate_number(t_dict *dict, char *number)
{
	int	max_dict_value;

	max_dict_value = get_max_dict_value(dict);
	if (ft_strlen(number) > max_dict_value + 2)
		;
	return (ft_strlen(number) < 40);
}
