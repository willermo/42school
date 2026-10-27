/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:56:05 by doriani           #+#    #+#             */
/*   Updated: 2023/06/09 23:21:20 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	usage(void)
{
	ft_printf("Usage: ./fract_ol <fractal> <size> <quality> <definition> ");
	ft_printf("[real part coordinate] [imaginary part coordinate]\n");
	ft_printf("\nAvailable fractals:\n");
	ft_printf("  - m (mandelbrot)\n");
	ft_printf("  - j (julia)\n");
	ft_printf("  - b (burning_ship)\n");
	ft_printf("\nAvailable sizes:\n");
	ft_printf("  - s (small: 640x480)\n");
	ft_printf("  - r (regular: 800x600)\n");
	ft_printf("  - l (large: 1024x768)\n");
	ft_printf("  - x (extralarge: 1280x1024)\n");
	ft_printf("  - u (ultralarge: 1920x1080)\n");
	ft_printf("\nAvailable qualities:\n");
	ft_printf("  - l (low)\n");
	ft_printf("  - m (medium)\n");
	ft_printf("  - h (high)\n");
	ft_printf("  - u (ultra)\n");
	ft_printf("\nAvailable definitions:\n");
	ft_printf("  - l (low definition - color bands)\n");
	ft_printf("  - h (hi-definiton - color transition)\n");
	ft_printf("\nComplex coordinates apply to julia set only\n");
	ft_printf("Nice coordinates to try are:\n-0.7\t0.27015\n");
	ft_printf("0.285\t0.01\n-0.8\t0.156\n-0.7269\t0.1889\n");
	ft_printf("-0.835\t-0.2321\n-0.4\t0.6\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (!valid_args(argc, argv))
		usage();
	init_fractal(&fractal, argv);
	init_system(&fractal.display, fractal.w, fractal.h, "Fract_ol");
	display_fractal(&fractal);
	mlx_hook(fractal.display.win, 2, 1L << 0, keypress, &fractal);
	mlx_hook(fractal.display.win, 17, 1L << 17, x_click, &fractal.display);
	mlx_mouse_hook(fractal.display.win, mouse_hook, &fractal);
	mlx_loop(fractal.display.mlx);
	destroy_image(&fractal.display, fractal.image);
	free(fractal.image);
	mlx_clear_window(fractal.display.mlx, fractal.display.win);
	mlx_destroy_window(fractal.display.mlx, fractal.display.win);
	mlx_destroy_display(fractal.display.mlx);
	free(fractal.display.mlx);
	return (0);
}
