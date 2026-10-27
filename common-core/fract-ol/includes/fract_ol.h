/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:50:16 by doriani           #+#    #+#             */
/*   Updated: 2023/06/09 20:13:18 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <X11/X.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_utils.h"
# include "colors.h"
# include <math.h>
# define ZOOM_FACTOR 0.1

typedef struct e_complex
{
	double	re;
	double	im;
}				t_complex;
typedef struct s_coord
{
	double	x;
	double	y;
}				t_coord;
typedef enum e_fractal_type
{
	mandelbrot,
	julia,
	burning_ship
}				t_fractal_type;
typedef enum e_definition
{
	lo_def,
	hi_def
}				t_definition;
typedef struct s_fractal	t_fractal;
typedef void				(*t_init_func)(t_fractal *fractal);
typedef void				(*t_draw_func)(t_fractal *fractal);
typedef struct s_fractal
{
	t_display		display;
	t_image			*image;
	t_fractal_type	type;
	t_definition	definition;
	t_init_func		init;
	t_draw_func		draw;
	int				max_iter;
	int				w;
	int				h;
	double			zoom_level;
	t_coord			center;
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
	t_complex		julia_c;
}				t_fractal;
/* inits */
int		valid_args(int argc, char **argv);
void	init_fractal(t_fractal *fractal, char **argv);
/* Fractals management */
void	init_mandelbrot(t_fractal *fractal);
void	draw_mandelbrot(t_fractal *fractal);
void	init_julia(t_fractal *fractal);
void	draw_julia(t_fractal *fractal);
void	init_ship(t_fractal *fractal);
void	draw_ship(t_fractal *fractal);
/* Utils */
void	display_fractal(t_fractal *fractal);
int		get_color_hi(t_fractal *f, double i, int offset);
int		get_color_lo(t_fractal *f, int i, int offset);
/* Movement */
void	move_up(t_fractal *fractal);
void	move_down(t_fractal *fractal);
void	move_left(t_fractal *fractal);
void	move_right(t_fractal *fractal);
void	zoom_in(t_fractal *fractal, int x, int y);
void	zoom_out(t_fractal *fractal, int x, int y);
/* Hooks */
int		keypress(int keycode, t_fractal *display);
int		x_click(t_display *display);
int		mouse_hook(int button, int x, int y, t_fractal *fractal);
#endif
