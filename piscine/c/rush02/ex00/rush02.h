/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 09:49:40 by doriani           #+#    #+#             */
/*   Updated: 2023/03/05 19:52:19 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "lib/ft_lib.h"

typedef int	t_file;
typedef struct s_dictionary
{
	char				*key;
	char				*value;
	struct s_dictionary	*next;
}	t_dict;
typedef enum e_mode
{
	invalid,
	standard,
	custom,
	interactive
}	t_mode;
t_mode	init(int argc, char **argv, t_dict **dictionary, char **number);
t_dict	*build_dictionary(t_file dict_file, t_dict **dictionary);
void	destroy_dictionary(t_dict *dictionary);
void	print_dictionary(t_dict *dictionary);
int		change_dictionary(char *file_name, t_dict **dictionary);
char	*value_of(t_dict *dict, char *key);
void	print_number(t_dict *dict, char *number);
void	print_0_19(t_dict *dict, int number);
void	print_20_99(t_dict *dict, int number);
void	print_100_999(t_dict *dict, int number);
int		readline(t_file dict_file, char line[]);
int		validate_dictionary(t_file dict_file);
int		validate_number(t_dict *dict, char *number);
char	*dict_value(t_dict *dictionary, char *number);
#endif
