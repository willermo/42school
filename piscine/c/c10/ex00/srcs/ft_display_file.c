/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 07:00:37 by doriani           #+#    #+#             */
/*   Updated: 2023/03/08 09:19:56 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "../includes/ft.h"

int	check_init(int argc, char **argv, t_file *filename)
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (2);
	}
	*filename = open(argv[1], O_RDONLY);
	if (*filename == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_file	file;
	char	c;

	if (check_init(argc, argv, &file))
		return (1);
	while (read(file, &c, 1))
		write(1, &c, 1);
	close(file);
	return (0);
}
