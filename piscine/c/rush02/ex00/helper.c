/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:08:52 by doriani           #+#    #+#             */
/*   Updated: 2023/03/05 19:55:52 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_dictionary(t_dict *dictionary)
{
	t_dict	*entry;

	entry = dictionary;
	while (entry != NULL)
	{
		ft_putstring("Key: ");
		ft_putstring(entry -> key);
		ft_putstring(" - Value: ");
		ft_putstring(entry -> value);
		ft_putstring("\n");
		entry = entry -> next;
	}
}

int	change_dictionary(char *file_name, t_dict **dictionary)
{
	t_file	dict_file;

	dict_file = open(file_name, O_RDONLY);
	if (dict_file == -1)
		return (0);
	destroy_dictionary(*dictionary);
	*dictionary = (t_dict *) malloc(sizeof(t_dict));
	*dictionary = build_dictionary(dict_file, dictionary);
	close(dict_file);
	return (1);
}

char	*dict_value(t_dict *dictionary, char *number)
{
	while (dictionary)
	{
		if (ft_strcmp(dictionary -> key, number) == 0)
			return (dictionary -> value);
		dictionary = dictionary -> next;
	}
	return (0);
}
