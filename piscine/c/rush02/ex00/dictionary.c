/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 09:56:10 by doriani           #+#    #+#             */
/*   Updated: 2023/03/06 15:39:40 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	readline(t_file dict_file, char line[])
{
	char	c;
	int		i;

	i = 0;
	while (read(dict_file, &c, 1))
	{
		if (c == '\n')
		{
			if (i == 0)
				continue ;
			else
				break ;
		}
		line[i++] = c;
	}
	if (i == 0)
		return (0);
	line[i] = '\0';
	return (1);
}

int	get_entry_data(char line[], char key[], char value[])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ft_char_is_space(line[i]))
		i++;
	if (!ft_char_is_numeric(line[i]))
		return (0);
	while (ft_char_is_numeric(line[i]))
	{
		key[j++] = line[i++];
	}
	key[j] = '\0';
	j = 0;
	while (line[i] != ':')
		i++;
	i++;
	while (ft_char_is_space(line[i]))
		i++;
	while (line[i])
		value[j++] = line[i++];
	value[j] = '\0';
	return (1);
}

t_dict	*add_entry(char key[], char value[])
{
	t_dict	*entry;

	entry = (t_dict *) malloc(sizeof(t_dict));
	entry -> key = (char *) malloc((ft_strlen(key) + 1) * sizeof (char));
	entry -> value = (char *) malloc((ft_strlen(value) + 1) * sizeof (char));
	ft_strcpy(entry -> key, key);
	ft_strcpy(entry -> value, value);
	entry -> next = NULL;
	return (entry);
	
}

void	destroy_dictionary(t_dict *dictionary)
{
	if (dictionary)
	{
		destroy_dictionary(dictionary -> next);
		free(dictionary -> key);
		free(dictionary -> value);
		free(dictionary);
	}
	return ;
}

t_dict	*build_dictionary(t_file dict_file, t_dict **dictionary)
{
	char	line[255];
	char	key[255];
	char	value[255];
	t_dict	*entry;

	entry = NULL;
	*dictionary = entry;
	if (readline(dict_file, line) && get_entry_data(line, key, value))
	{
		entry = add_entry(key, value);
		*dictionary = entry;
	}
	else
		return (0);
	while (readline(dict_file, line))
	{
		if (get_entry_data(line, key, value) == 0)
		{
			destroy_dictionary(*dictionary);
			return (0);
		}
		entry -> next = add_entry(key, value);
		entry = entry-> next;
	}
	return (*dictionary);
}
