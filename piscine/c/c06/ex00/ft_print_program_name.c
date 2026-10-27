/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:26:53 by doriani           #+#    #+#             */
/*   Updated: 2023/02/23 12:36:03 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	int	len;

	(void) argc;
	len = ft_strlen(argv[0]);
	write(1, argv[0], len);
	write(1, "\n", 1);
	return (0);
}
