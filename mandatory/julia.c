/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 00:32:41 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/05 12:16:06 by anktiri          ###   ########.fr       */
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
	if (iter == fract->iteration)
		return (BLACK);
	fract->red = (iter * 2) % 256;
	fract->green = (iter * 6) % 256;
	fract->blue = (iter * 12) % 256;
	return ((fract->red << 16) + (fract->green << 8) + fract->blue);
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
		id->z.i = 2 * id->z.r * id->z.i + id->julia_c.i;
		id->z.r = zr_tmp + id->julia_c.r;
		iter++;
	}
	return (iter);
}

void	julia_render(t_mlx *fract)
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
			fract->c.i = -((((double)y * (IMG_MAX - IMG_MIN) / HEIGHT)
						+ IMG_MIN) * fract->zoom) + fract->axis_y;
			iter = iteration(fract);
			put_pixel(&fract->img, x, y, get_color(iter, fract));
		}
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img.img_ptr,
		0, 0);
}
