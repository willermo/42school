/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:48:11 by doriani           #+#    #+#             */
/*   Updated: 2023/06/09 20:22:54 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	keypress(int ks, t_fractal *f)
{
	if (ks == 0xFF1B)
		mlx_loop_end(f->display.mlx);
	if (ks == 0x72)
		f->init(f);
	if (ks == 0xff52)
		move_up(f);
	if (ks == 0xff54)
		move_down(f);
	if (ks == 0xff53)
		move_right(f);
	if (ks == 0xff51)
		move_left(f);
	if (ks == 0xffab)
		zoom_in(f, f->w / 2, f->h / 2);
	if (ks == 0xffad)
		zoom_out(f, f->w / 2, f->h / 2);
	if (ks == 0xff52 || ks == 0xff54 || ks == 0xff53 || ks == 0xff51
		|| ks == 0xffab || ks == 0xffad || ks == 0x72)
		f->draw(f);
	return (0);
}

int	x_click(t_display *display)
{
	mlx_loop_end(display->mlx);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *f)
{
	double	width;
	double	height;

	width = f->x_max - f->x_min;
	height = f->y_max - f->y_min;
	if (button == 4 || button == 5)
	{
		f->center.x = width * x / (double)f->w + f->x_min;
		f->center.y = height * y / (double)f->h + f->y_min;
	}
	if (button == 4)
		zoom_in(f, x, y);
	if (button == 5)
		zoom_out(f, x, y);
	if (button == 4 || button == 5)
		f->draw(f);
	return (0);
}
