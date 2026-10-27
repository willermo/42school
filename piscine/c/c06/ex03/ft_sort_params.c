/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:36:33 by doriani           #+#    #+#             */
/*   Updated: 2023/02/23 14:46:25 by doriani          ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

void	sort(int argc, char **args)
{
	int		i;
	int		j;
	char	*t;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(args[j], args[i]) < 0)
			{
				t = args[i];
				args[i] = args[j];
				args[j] = t;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*program;

	i = 0;
	program = argv[0];
	sort(argc, argv);
	while (i < argc)
	{
		if (ft_strcmp(argv[i], program))
		{
			write(1, argv[i], ft_strlen(argv[i]));
			write(1, "\n", 1);
		}
		i++;
	}
	return (0);
}
