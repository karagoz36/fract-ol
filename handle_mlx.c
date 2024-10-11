/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:11:31 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/07/09 15:16:23 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free(t_fractal *fractal)
{
	if (fractal->img)
		mlx_destroy_image(fractal->mlx, fractal->img);
	if (fractal->win)
		mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
}

int	handle_close(t_fractal *fractal)
{
	ft_free(fractal);
	return (0);
}

int	handle_key(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
		ft_free(fractal);
	else if (keycode == 65361)
		fractal->offset_x -= 0.1 / fractal->zoom;
	else if (keycode == 65363)
		fractal->offset_x += 0.1 / fractal->zoom;
	else if (keycode == 65362)
		fractal->offset_y -= 0.1 / fractal->zoom;
	else if (keycode == 65364)
		fractal->offset_y += 0.1 / fractal->zoom;
	fractal_setup(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	return (0);
}

int	handle_mouse(int keycode, int x, int y, t_fractal *fractal)
{
	if (keycode == 4)
		fractal->zoom *= 1.1;
	else if (keycode == 5)
		fractal->zoom /= 1.1;
	fractal_setup(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	(void)x;
	(void)y;
	return (0);
}
