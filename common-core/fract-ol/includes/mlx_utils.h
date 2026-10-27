/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:09:07 by doriani           #+#    #+#             */
/*   Updated: 2023/06/09 20:10:11 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H
# include "mlx.h"
# define LE	0
# define BE	1

typedef struct s_display
{
	void	*mlx;
	void	*win;
}				t_display;
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_image;
typedef struct s_point
{
	int	x;
	int	y;
}				t_point;
void	init_system(t_display *display, int width, int height, char *title);
int		get_endianness(void);
t_image	*create_image(t_display *display, int width, int height);
void	add_image(t_display *display, t_image *img, t_point p);
void	destroy_image(t_display *display, t_image *img);
void	change_image(t_display *display, t_image *img);
void	draw_pixel(t_image *data, t_point coord, int color);
#endif
