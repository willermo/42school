/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:48:09 by doriani           #+#    #+#             */
/*   Updated: 2023/06/09 19:55:32 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	display_fractal(t_fractal *f)
{
	f->init(f);
}

int	get_color_hi(t_fractal *f, double i, int offset)
{
	t_hsv	hsv;

	if (i == f->max_iter)
		return (0x000000);
	hsv.h = fmod((360.0 * i / f->max_iter) + offset, 360.0);
	hsv.s = 1;
	hsv.v = 1;
	return (t_hsv_to_int(hsv));
}

int	get_color_lo(t_fractal *f, int i, int offset)
{
	t_hsv	hsv;

	if (i == f->max_iter)
		return (0x000000);
	hsv.h = (360 * i / f->max_iter + offset) % 360;
	hsv.s = 1;
	hsv.v = 1;
	return (t_hsv_to_int(hsv));
}
