/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:00:10 by doriani           #+#    #+#             */
/*   Updated: 2023/03/08 16:45:31 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../includes/ft.h"

void	check_init(int argc, char **argv, t_file **filelist)
{
	int	n_files;

	n_files = 0;
	*filelist = (t_file *) malloc(argc * sizeof(t_file));
	if (argc == 1)
		(*filelist)-> fd = 1;
		(*filelist)-> name = 0;
	if (argc > 2)
	{
		while (++n_files < argc)
		{
			filelist[n_files]-> fd = open(argv[n_files], O_RDONLY);
			filelist[n_files]-> name = argv[n_files];
		}
	}
}

int	main(int argc, char **argv)
{
	t_file	*filelist;
	char	buf;

	check_init(argc, argv, &filelist);
	return (0);
}
