/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_validators.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:12:51 by doriani           #+#    #+#             */
/*   Updated: 2023/06/09 17:20:37 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	valid_fractal(char *fractal)
{
	if (!ft_strcmp(fractal, "m"))
		return (1);
	if (!ft_strcmp(fractal, "j"))
		return (1);
	if (!ft_strcmp(fractal, "b"))
		return (1);
	return (0);
}

static int	valid_size(char *size)
{
	if (!ft_strcmp(size, "s"))
		return (1);
	if (!ft_strcmp(size, "r"))
		return (1);
	if (!ft_strcmp(size, "l"))
		return (1);
	if (!ft_strcmp(size, "x"))
		return (1);
	if (!ft_strcmp(size, "u"))
		return (1);
	return (0);
}

static int	valid_quality(char *quality)
{
	if (!ft_strcmp(quality, "l"))
		return (1);
	if (!ft_strcmp(quality, "m"))
		return (1);
	if (!ft_strcmp(quality, "h"))
		return (1);
	if (!ft_strcmp(quality, "u"))
		return (1);
	return (0);
}

static int	valid_definiton(char *definition)
{
	if (!ft_strcmp(definition, "l"))
		return (1);
	if (!ft_strcmp(definition, "h"))
		return (1);
	return (0);
}

int	valid_args(int argc, char **argv)
{
	if (argc < 5)
		return (0);
	if (!ft_strcmp(argv[1], "j") && argc < 7)
		return (0);
	if (!valid_fractal(argv[1]))
		return (0);
	if (!valid_size(argv[2]))
		return (0);
	if (!valid_quality(argv[3]))
		return (0);
	if (!valid_definiton(argv[4]))
		return (0);
	return (1);
}
