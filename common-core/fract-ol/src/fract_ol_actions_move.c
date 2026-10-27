/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_actions_move.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:33:22 by doriani           #+#    #+#             */
/*   Updated: 2023/06/09 19:05:41 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	move_up(t_fractal *f)
{
	double	height;

	height = f->y_max - f->y_min;
	f->y_min -= height * 0.1;
	f->y_max -= height * 0.1;
	f->center.y -= height * 0.1;
	f->draw(f);
}

void	move_down(t_fractal *f)
{
	double	height;

	height = f->y_max - f->y_min;
	f->y_min += height * 0.1;
	f->y_max += height * 0.1;
	f->center.y += height * 0.1;
	f->draw(f);
}

void	move_left(t_fractal *f)
{
	double	width;

	width = f->x_max - f->x_min;
	f->x_min -= width * 0.1;
	f->x_max -= width * 0.1;
	f->center.x -= width * 0.1;
	f->draw(f);
}

void	move_right(t_fractal *f)
{
	double	width;

	width = f->x_max - f->x_min;
	f->x_min += width * 0.1;
	f->x_max += width * 0.1;
	f->center.x += width * 0.1;
	f->draw(f);
}
