/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:58:51 by doriani           #+#    #+#             */
/*   Updated: 2023/06/09 23:12:08 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static double	julia_iters_hi(t_fractal *f, t_complex z)
{
	t_complex	c;
	int			i;

	c = (t_complex){.re = f->julia_c.re, .im = f->julia_c.im};
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < f->max_iter)
	{
		z = (t_complex){.re = z.re * z.re - z.im * z.im + c.re,
			.im = z.re * z.im + z.im * z.re + c.im};
		i++;
	}
	if (i == f->max_iter)
		return ((double)i);
	return (i + 1 - log(log2(sqrt(fabs(z.re * z.re + z.im * z.im)))));
}

static int	julia_iters_lo(t_fractal *f, t_complex z)
{
	t_complex	c;
	int			i;

	c = (t_complex){.re = f->julia_c.re, .im = f->julia_c.im};
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < f->max_iter)
	{
		z = (t_complex){.re = z.re * z.re - z.im * z.im + c.re,
			.im = z.re * z.im + z.im * z.re + c.im};
		i++;
	}
	return (i);
}

static void	render_julia(t_fractal *f, t_image *image)
{
	t_point		p;
	t_complex	z;
	int			color;

	p.y = 0;
	while (p.y < f->h)
	{
		p.x = 0;
		while (p.x < f->w)
		{
			z.re = f->x_min + (p.x / (f->w - 1.0)) * (f->x_max - f->x_min);
			z.im = f->y_min + (p.y / (f->h - 1.0)) * (f->y_max - f->y_min);
			if (f->definition == hi_def)
				color = get_color_hi(f, julia_iters_hi(f, z), f->zoom_level);
			else
				color = get_color_lo(f, julia_iters_lo(f, z), f->zoom_level);
			draw_pixel(image, p, color);
			p.x++;
		}
		p.y++;
	}
}

void	init_julia(t_fractal *f)
{
	f->x_min = -1.5;
	f->x_max = 1.5;
	f->y_max = f->h * (f->x_max - f->x_min) / f->w / 2;
	f->y_min = f->y_max * -1;
	f->center.x = (f->x_max + f->x_min) / 2;
	f->center.y = (f->y_max + f->y_min) / 2;
	f->zoom_level = 1.0;
	draw_julia(f);
}

void	draw_julia(t_fractal *f)
{
	t_image	*image;

	image = create_image(&f->display, f->w, f->h);
	render_julia(f, image);
	if (f->image)
	{
		destroy_image(&f->display, f->image);
		free(f->image);
	}
	f->image = image;
	add_image(&f->display, f->image, (t_point){0, 0});
}
