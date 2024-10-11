/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:18:31 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/07/09 15:28:47 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define ON_DESTROY 17

typedef struct s_fractal {
	int			type;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		cx;
	double		cy;
}				t_fractal;

void	put_pixel(t_fractal *fractal, int x, int y, int color);
int		handle_close(t_fractal *fractal);
int		handle_key(int keycode, t_fractal *fractal);
int		handle_mouse(int keycode, int x, int y, t_fractal *fractal);
void	ft_free(t_fractal *fractal);
void	fractal_setup(t_fractal *fractal);
void	julia_starters(t_fractal *fractal, char **argv);

#endif