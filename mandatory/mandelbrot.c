/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:43:41 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/05 13:30:29 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	put_pixel(t_image *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->line_len + x * (img->bitspp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static unsigned int	get_color(int iter, t_mlx *fract)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == fract->iteration)
		return (BLACK);
	t = (double)iter / fract->iteration;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r * 65536 + g * 256 + b);
}

static int	iteration(t_mlx *id)
{
	int		iter;
	double	zr_tmp;

	iter = 0;
	id->z.r = id->c.r;
	id->z.i = id->c.i;
	while (((pow(id->z.r, 2) + pow(id->z.i, 2)) < 4) && iter < id->iteration)
	{
		zr_tmp = pow(id->z.r, 2) - pow(id->z.i, 2);
		id->z.i = 2 * id->z.r * id->z.i + id->c.i;
		id->z.r = zr_tmp + id->c.r;
		iter++;
	}
	return (iter);
}

void	mandelbrot_render(t_mlx *fract)
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
			fract->c.r = ((((double)x * (REAL_MAX - REAL_MIN) / WIDTH)
						+ REAL_MIN) * fract->zoom) + fract->axis_x;
			fract->c.i = ((((double)y * (IMG_MAX - IMG_MIN) / HEIGHT) + IMG_MIN)
					* fract->zoom) + fract->axis_y;
			iter = iteration(fract);
			put_pixel(&fract->img, x, y, get_color(iter, fract));
		}
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img.img_ptr,
		0, 0);
}
