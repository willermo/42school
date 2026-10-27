/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_actions_zoom.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:35:30 by doriani           #+#    #+#             */
/*   Updated: 2023/06/09 20:20:20 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	zoom_in(t_fractal *f, int x, int y)
{
	double	width;
	double	height;

	f->zoom_level += 25;
	width = (f->x_max - f->x_min);
	height = (f->y_max - f->y_min);
	f->center.x = width * x / (double)f->w + f->x_min;
	f->center.y = height * y / (double)f->h + f->y_min;
	width *= (1 - ZOOM_FACTOR);
	height *= (1 - ZOOM_FACTOR);
	f->x_min = f->center.x - (width / 2);
	f->x_max = f->center.x + (width / 2);
	f->y_min = f->center.y - (height / 2);
	f->y_max = f->center.y + (height / 2);
	f->draw(f);
}

void	zoom_out(t_fractal *f, int x, int y)
{
	double	width;
	double	height;

	f->zoom_level += 25;
	width = (f->x_max - f->x_min);
	height = (f->y_max - f->y_min);
	f->center.x = width * x / (double)f->w + f->x_min;
	f->center.y = height * y / (double)f->h + f->y_min;
	width *= (1 + ZOOM_FACTOR);
	height *= (1 + ZOOM_FACTOR);
	f->x_min = f->center.x - (width / 2);
	f->x_max = f->center.x + (width / 2);
	f->y_min = f->center.y - (height / 2);
	f->y_max = f->center.y + (height / 2);
	f->draw(f);
}
