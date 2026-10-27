/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:12:58 by doriani           #+#    #+#             */
/*   Updated: 2023/03/05 18:43:37 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_mode	init_1(t_dict **dictionary, char **number)
{
	t_file	dict_file;

	dict_file = open("dicts/numbers.dict", O_RDONLY);
	if (dict_file == -1 || !validate_dictionary(dict_file))
		return (invalid);
	close(dict_file);
	dict_file = open("dicts/numbers.dict", O_RDONLY);
	*dictionary = build_dictionary(dict_file, dictionary);
	close(dict_file);
	*number = 0;
	return (interactive);
}

t_mode	init_2(char **argv, t_dict **dictionary, char **number)
{
	t_file	dict_file;

	dict_file = open("dicts/numbers.dict", O_RDONLY);
	if (dict_file == -1 || !validate_dictionary(dict_file))
		return (invalid);
	close(dict_file);
	dict_file = open("dicts/numbers.dict", O_RDONLY);
	*dictionary = build_dictionary(dict_file, dictionary);
	close(dict_file);
	*number = (char *) malloc((ft_strlen(argv[1]) + 1) * sizeof(char));
	ft_strcpy(*number, argv[1]);
	return (standard);
}

t_mode	init_3(char **argv, t_dict **dictionary, char **number)
{
	t_file	dict_file;

	dict_file = open(argv[1], O_RDONLY);
	if (dict_file == -1 || !validate_dictionary(dict_file))
		return (invalid);
	close(dict_file);
	dict_file = open(argv[1], O_RDONLY);
	*dictionary = build_dictionary(dict_file, dictionary);
	close(dict_file);
	*number = (char *) malloc((ft_strlen(argv[2]) + 1) * sizeof(char));
	ft_strcpy(*number, argv[2]);
	return (custom);
}

t_mode	init(int argc, char **argv, t_dict **dictionary, char **number)
{
	if (argc > 3)
		return (invalid);
	if (argc == 3)
		return (init_3(argv, dictionary, number));
	if (argc == 2)
		return (init_2(argv, dictionary, number));
	if (argc == 1)
		return (init_1(dictionary, number));
	return (invalid);
}
