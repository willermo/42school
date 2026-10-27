/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:03:14 by doriani           #+#    #+#             */
/*   Updated: 2023/06/09 23:04:31 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static double	ship_iters_hi(t_fractal *f, t_complex c)
{
	t_complex	z;
	int			i;

	z = (t_complex){.re = 0, .im = 0};
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < f->max_iter)
	{
		z = (t_complex){.re = z.re * z.re - z.im * z.im + c.re,
			.im = 2 * fabs(z.re * z.im) + c.im};
		i++;
	}
	if (i == f->max_iter)
		return ((double)i);
	return (i + 1 - log(log2(sqrt(fabs(z.re * z.re + z.im * z.im)))));
}

static int	ship_iters_lo(t_fractal *f, t_complex c)
{
	t_complex	z;
	int			i;

	z = (t_complex){.re = 0, .im = 0};
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < f->max_iter)
	{
		z = (t_complex){.re = z.re * z.re - z.im * z.im + c.re,
			.im = 2 * fabs(z.re * z.im) + c.im};
		i++;
	}
	return (i);
}

static void	render_ship(t_fractal *f, t_image *image)
{
	t_point		p;
	t_complex	c;
	int			color;

	p.y = 0;
	while (p.y < f->h)
	{
		p.x = 0;
		while (p.x < f->w)
		{
			c.re = f->x_min + (p.x / (f->w - 1.0)) * (f->x_max - f->x_min);
			c.im = f->y_min + (p.y / (f->h - 1.0)) * (f->y_max - f->y_min);
			if (f->definition == hi_def)
				color = get_color_hi(f, ship_iters_hi(f, c), f->zoom_level);
			else
				color = get_color_lo(f, ship_iters_lo(f, c), f->zoom_level);
			draw_pixel(image, p, color);
			p.x++;
		}
		p.y++;
	}
}

void	init_ship(t_fractal *f)
{
	f->x_min = -2.0;
	f->x_max = 1.5;
	f->y_max = f->h * (f->x_max - f->x_min) / f->w / 2 - 0.5;
	f->y_min = f->h * (f->x_max - f->x_min) / f->w / -2 - 0.5;
	f->center.x = (f->x_max + f->x_min) / 2;
	f->center.y = (f->y_max + f->y_min) / 2;
	f->zoom_level = 1.0;
	draw_ship(f);
}

void	draw_ship(t_fractal *f)
{
	t_image	*image;

	image = create_image(&f->display, f->w, f->h);
	render_ship(f, image);
	if (f->image)
	{
		destroy_image(&f->display, f->image);
		free(f->image);
	}
	f->image = image;
	add_image(&f->display, f->image, (t_point){0, 0});
}
