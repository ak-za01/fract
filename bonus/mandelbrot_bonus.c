/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:43:41 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/07 17:39:45 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol_bonus.h"

void	put_pixel(t_image *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->line_len + x * (img->bitspp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

unsigned int	get_color(int iter, t_mlx *fract)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == fract->iteration)
		return (BLACK);
	t = (double)iter / fract->iteration;
	r = (int)(9 * (1 - t) * (1 - t) * t * 200) + fract->red;
	g = (int)(15 * (1 - t) * t * t * 220) + fract->green;
	b = (int)(8.5 * (1 - t) * t * t * 235) + fract->blue;
	return (r << 16 | g << 8 | b);
}

void	render_fractal(double zr_tmp, t_mlx *id)
{
	if (id->flag == 0)
	{
		id->z.i = 2 * id->z.r * id->z.i + id->c.i;
		id->z.r = zr_tmp + id->c.r;
	}
	else if (id->flag == 1)
	{
		id->z.i = fabs(2 * id->z.r * id->z.i + id->c.i);
		id->z.r = fabs(zr_tmp + id->c.r);
	}
	else if (id->flag == 2)
	{
		id->z.i = -2 * id->z.r * id->z.i + id->c.i;
		id->z.r = zr_tmp + id->c.r;
	}
	else if (id->flag == 3)
	{
		id->z.i = 2 * id->z.r * id->z.i + id->julia_c.i;
		id->z.r = zr_tmp + id->julia_c.r;
	}
}

static int	iteration(t_mlx *id)
{
	int		iter;
	double	zr_tmp;

	iter = 0;
	if (id->flag == 1)
	{
		id->z.r = 0;
		id->z.i = 0;
	}
	else
	{
		id->z.r = id->c.r;
		id->z.i = id->c.i;
	}
	while (((id->z.r * id->z.r + id->z.i * id->z.i) < 4)
		&& iter < id->iteration)
	{
		zr_tmp = id->z.r * id->z.r - id->z.i * id->z.i;
		render_fractal(zr_tmp, id);
		iter++;
	}
	return (iter);
}

void	render(t_mlx *fract)
{
	int	iter;
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			fract->c.r = map_x(x, fract);
			fract->c.i = map_y(y, fract);
			if (fract->flag == 4)
				iter = calc_mandelbox(fract, &fract->c);
			else
				iter = iteration(fract);
			put_pixel(&fract->img, x, y, get_color(iter, fract));
		}
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img.img_ptr,
		0, 0);
}
