/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:16:44 by doriani           #+#    #+#             */
/*   Updated: 2023/06/09 20:24:38 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "mlx_utils.h"

t_image	*create_image(t_display *display, int width, int height)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	image->width = width;
	image->height = height;
	image->img = mlx_new_image(display->mlx, image->width, image->height);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	return (image);
}

void	add_image(t_display *display, t_image *image, t_point p)
{
	mlx_put_image_to_window(display->mlx, display->win, image->img, p.x, p.y);
}

void	destroy_image(t_display *display, t_image *image)
{
	mlx_destroy_image(display->mlx, image->img);
}

void	change_image(t_display *display, t_image *image)
{
	destroy_image(display, image);
	image->img = mlx_new_image(display->mlx, image->width, image->height);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
}

void	draw_pixel(t_image *image, t_point coord, int color)
{
	char	*pixel;
	int		i;

	i = image->bits_per_pixel - 8;
	if (coord.x < 0 || coord.x >= image->width
		|| coord.y < 0 || coord.y >= image->height)
		return ;
	pixel = image->addr + (coord.y * image->line_length \
							+ coord.x * (image->bits_per_pixel / 8));
	while (i >= 0)
	{
		if (image->endian == BE)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (image->bits_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
	}
}
