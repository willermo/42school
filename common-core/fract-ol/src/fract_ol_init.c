/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:42:07 by doriani           #+#    #+#             */
/*   Updated: 2023/06/10 09:36:08 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	init_type(t_fractal *f, char **argv)
{
	f->julia_c = (t_complex){0.0, 0.0};
	if (argv[1][0] == 'm')
	{
		f->type = mandelbrot;
		f->init = init_mandelbrot;
		f->draw = draw_mandelbrot;
	}
	else if (argv[1][0] == 'j')
	{
		f->type = julia;
		f->julia_c = (t_complex){ft_atod(argv[5]), ft_atod(argv[6])};
		f->init = init_julia;
		f->draw = draw_julia;
	}
	else if (argv[1][0] == 'b')
	{
		f->type = burning_ship;
		f->init = init_ship;
		f->draw = draw_ship;
	}
}

static void	init_size(t_fractal *f, char size)
{
	if (size == 's')
	{
		f->w = 640;
		f->h = 480;
	}
	else if (size == 'r')
	{
		f->w = 800;
		f->h = 600;
	}
	else if (size == 'l')
	{
		f->w = 1024;
		f->h = 768;
	}
	else if (size == 'x')
	{
		f->w = 1280;
		f->h = 1024;
	}
	else if (size == 'u')
	{
		f->w = 1920;
		f->h = 1080;
	}
}

static void	init_quality(t_fractal *f, char quality)
{
	if (quality == 'l')
		f->max_iter = 50;
	else if (quality == 'm')
		f->max_iter = 80;
	else if (quality == 'h')
		f->max_iter = 200;
	else if (quality == 'u')
		f->max_iter = 1000;
}

static void	init_definition(t_fractal *f, char definition)
{
	if (definition == 'l')
		f->definition = lo_def;
	else if (definition == 'h')
		f->definition = hi_def;
}

void	init_fractal(t_fractal *f, char **argv)
{
	f->image = NULL;
	f->display.mlx = NULL;
	f->display.win = NULL;
	init_type(f, argv);
	init_size(f, argv[2][0]);
	init_quality(f, argv[3][0]);
	init_definition(f, argv[4][0]);
	f->zoom_level = 0;
}
