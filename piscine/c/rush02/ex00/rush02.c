/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 09:49:12 by doriani           #+#    #+#             */
/*   Updated: 2023/03/05 20:08:43 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_invalid(char *number)
{
	if (! *number)
		return (1);
	while (*number)
	{
		if (*number < '0' || *number > '9')
			return (1);
		number++;
	}
	return (0);
}

int	dict_has_key(t_dict *dict, char *number)
{
	while (dict)
	{
		if (ft_strcmp(number, dict -> key) == 0)
			return (1);
		dict = dict -> next;
	}
	return (0);
}

int	interactive_mode(t_dict *dict)
{
	char	number[255];
	int		i;

	i = 0;
	write(1, "Interactive mode started.\nEnter a number> ", 43);
	read(0, &number[i], 1);
	while (number[i] != '\n')
		read(0, &number[++i], 1);
	number[i] = '\0';
	if (is_invalid(number))
	{
		ft_putstring("Error");
		return (1);
	}
	if (!validate_number(dict, number))
	{
		if (dict_has_key(dict, number))
			ft_putstring(dict_value(dict, number));
		else
			ft_putstring("Dict Error");
		return (1);
	}
	print_number(dict, number);
	return (0);
}

int	regular_mode(t_dict *dict, char *number)
{
	if (is_invalid(number))
	{
		ft_putstring("Error");
		return (1);
	}
	if (!validate_number(dict, number))
	{
		if (dict_has_key(dict, number))
			ft_putstring(dict_value(dict, number));
		else
			ft_putstring("Dict Error");
		return (1);
	}
	print_number(dict, number);
	return (0);
}

int	main(int argc, char **argv)
{
	t_dict	*dict;
	char	*number;
	t_mode	mode;

	mode = init(argc, argv, &dict, &number);
	if (mode == invalid)
	{
		ft_putstring("Dict Error\n");
		return (1);
	}
	if (mode == standard || mode == custom)
		regular_mode(dict, number);
	else if (mode == interactive)
		interactive_mode(dict);
	ft_putstring("\n");
	destroy_dictionary(dict);
	if (number)
		free(number);
	return (0);
}
