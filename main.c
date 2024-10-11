/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:46:35 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/07/10 15:21:36 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 800 && y >= 0 && y < 800)
	{
		dst = fractal->addr + (y * fractal->line_length
				+ x * (fractal->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void static	handle_args(t_fractal *fractal, int argc, char **argv)
{
	if (!(argc == 2 || (argc == 4 && ft_strncmp("julia", argv[1], 5) == 0)))
	{
		ft_putendl_fd("No valid arguments! You can use one of these parameters:\
		\n1)mandelbrot\n2)julia (x.y, z.t)\n3)burning_ship", 1);
		exit (1);
	}
	if (ft_strncmp("mandelbrot", argv[1], 10) == 0 && !argv[1][10])
		fractal->type = MANDELBROT;
	else if (ft_strncmp("julia", argv[1], 5) == 0 && !argv[1][5])
		fractal->type = JULIA;
	else if (ft_strncmp("burning_ship", argv[1], 12) == 0 && !argv[1][12])
		fractal->type = BURNING_SHIP;
	else
	{
		ft_putendl_fd("2No valid arguments! You can use one of these parameters:\
		\n1)mandelbrot\n2)julia (x.y, z.t)\n3)burning_ship", 1);
		exit (1);
	}
	if (fractal->type == JULIA && argc == 4)
		julia_starters(fractal, argv);
}
#include<stdio.h>
void static	initialize(t_fractal *fractal, int argc)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		exit(1);
	fractal->win = mlx_new_window(fractal->mlx, 800, 800, "Fractol");
	fractal->img = mlx_new_image(fractal->mlx, 800, 800);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	printf("BPL:%d\nLL.:%d\n", fractal->bits_per_pixel, fractal->line_length);
	if (!fractal->win || !fractal->img || !fractal->addr)
		exit(1);
	fractal->zoom = 1.0;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
	if (fractal->type == JULIA && argc == 2)
	{
		fractal->cx = 0.4;
		fractal->cy = 0.6;
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	handle_args(&fractal, argc, argv);
	initialize(&fractal, argc);
	fractal_setup(&fractal);
	mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.img, 0, 0);
	mlx_hook(fractal.win, 17, 0, handle_close, &fractal);
	mlx_key_hook(fractal.win, handle_key, &fractal);
	mlx_mouse_hook(fractal.win, handle_mouse, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
