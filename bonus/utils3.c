/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:39:23 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/07 06:11:34 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol_bonus.h"

static double	box_fold(double z)
{
	if (z > 1)
		z = 2 - z;
	else if (z < -1)
		z = -2 - z;
	return (z);
}

static double	ball_fold(double r, double m)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
}

int	calc_mandelbox(t_mlx *fract, t_complex *c)
{
	double		mag;
	t_complex	z;
	int			i;

	i = -1;
	mag = 0;
	z.r = c->r;
	z.i = c->i;
	while ((sqrt(mag) < 2) && (++i < fract->iteration))
	{
		z.r = 1 * box_fold(z.r);
		z.i = 1 * box_fold(z.i);
		mag = sqrt(z.r * z.r + z.i * z.i);
		z.r = z.r * 2 * ball_fold(0.5, mag) + c->r;
		z.i = z.i * 2 * ball_fold(0.5, mag) + c->i;
	}
	return (i);
}

double	map_x(int x, t_mlx *data)
{
	return (((x - WIDTH / 2.0) / (data->zoom * WIDTH)) + data->axis_x);
}

double	map_y(int y, t_mlx *data)
{
	return (((y - HEIGHT / 2.0) / (data->zoom * HEIGHT)) + data->axis_y);
}
