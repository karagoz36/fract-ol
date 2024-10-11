/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:08:36 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/07/09 15:34:47 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void static	ft_atof_2(int i, const char *str, double *number)
{
	double	div;

	div = 0.1;
	while (str[i] && ft_isdigit((unsigned char) str[i]))
	{
		*number = *number + div * (str[i++] - '0');
		div *= 0.1;
	}
}

double static	ft_atof(const char *str)
{
	double	number;
	double	sign;
	int		i;

	number = 0.0;
	sign = 1.0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
			sign = -1;
			i++;
	}
	while (str[i] && ft_isdigit((unsigned char) str[i]))
	{
		number = (number * 10.0 + str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		ft_atof_2(i + 1, str, &number);
	return (sign * number);
}

void	julia_starters(t_fractal *fractal, char **argv)
{
	fractal->cx = ft_atof(argv[2]);
	fractal->cy = ft_atof(argv[3]);
	if ((fractal->cx <= -2 || fractal->cx >= 2)
		|| (fractal->cy <= -2 || fractal->cy >= 2))
	{
		ft_putendl_fd("Arguments for Julia should be between -2 and 2!\nExamples:\
		\n-0.70176 -0.3842\n-0.835 -0.2321\n0.285 0.01", 1);
		exit(1);
	}
}
