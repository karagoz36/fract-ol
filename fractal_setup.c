/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:10:00 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/07/09 16:09:10 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void static	mandelbrot(int x, int y, int i, t_fractal *fractal)
{
	double	zx;
	double	zy;
	double	temp;

	zx = 0.0;
	zy = 0.0;
	fractal->cx = (x - 400) / (200.0 * fractal->zoom) + fractal->offset_x;
	fractal->cy = (y - 400) / (200.0 * fractal->zoom) + fractal->offset_y;
	while (i <= 150 && zx * zx + zy * zy < 4)
	{
		temp = zx * zx - zy * zy + fractal->cx;
		zy = 2.0 * zx * zy + fractal->cy;
		zx = temp;
		i++;
	}
	if (i == 150)
		put_pixel(fractal, x, y, 0x000000);
	else
		put_pixel(fractal, x, y, 0xFCBE11 * i);
}

void static	julia(int x, int y, int i, t_fractal *fractal)
{
	double	zx;
	double	zy;
	double	temp;

	zx = (x - 400) / (200.0 * fractal->zoom) + fractal->offset_x;
	zy = (y - 400) / (200.0 * fractal->zoom) + fractal->offset_y;
	while (i <= 150 && zx * zx + zy * zy < 4)
	{
		temp = zx * zx - zy * zy + fractal->cx;
		zy = 2.0 * zx * zy + fractal->cy;
		zx = temp;
		i++;
	}
	if (i == 150)
		put_pixel(fractal, x, y, 0x000000);
	else
		put_pixel(fractal, x, y, 0xFCBE11 * (i % 255) * 5);
}

void static	burning_ship(int x, int y, int i, t_fractal *fractal)
{
	double	zx;
	double	zy;
	double	temp;

	zx = 0.0;
	zy = 0.0;
	fractal->cx = (x - 400) / (200.0 * fractal->zoom) + fractal->offset_x;
	fractal->cy = (y - 400) / (200.0 * fractal->zoom) + fractal->offset_y;
	while (i <= 150 && zx * zx + zy * zy < 4)
	{
		temp = zx * zx - zy * zy + fractal->cx;
		if (2.0 * zx * zy < 0)
			zy = -(2.0 * zx * zy) + fractal->cy;
		else
			zy = 2.0 * zx * zy + fractal->cy;
		if (temp < 0)
			temp = -temp;
		zx = temp;
		i++;
	}
	if (i == 150)
		put_pixel(fractal, x, y, 0x000000);
	else
		put_pixel(fractal, x, y, 0xFCBE11 * i);
}

void	fractal_setup(t_fractal *fractal)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 800)
	{
		y = -1;
		while (++y < 800)
		{
			if (fractal->type == 1)
				mandelbrot(x, y, 0, fractal);
			else if (fractal->type == 2)
				julia (x, y, 0, fractal);
			else if (fractal->type == 3)
				burning_ship(x, y, 0, fractal);
		}
	}
}
