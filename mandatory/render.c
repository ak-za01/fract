/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akza <akza@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:43:41 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/01 03:12:11 by akza             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	put_pixel(t_image *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->line_len + x * (img->bitspp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

unsigned int	get_color(int iter, t_mlx *fract)
{
	int	red;
	int	green;
	int	blue;

	if (iter == fract->iteration)
		return (BLACK);
	red = (iter * 25) % 256;
	green = (iter * 2) % 256;
	blue = (iter * 5) % 256;
	return ((red << 16) + (green << 8) + blue);
}

int	iteration(t_mlx *id)
{
	int		iter;
	double	zr_tmp;

	iter = 0;
	id->z.r = 0;
	id->z.i = 0;
	while (((pow(id->z.r, 2) + pow(id->z.i, 2)) < 4) && iter < id->iteration)
	{
		zr_tmp = pow(id->z.r, 2) - pow(id->z.i, 2);
		id->z.i = 2 * id->z.r * id->z.i + id->c.i;
		id->z.r = zr_tmp + id->c.r;
		iter++;
	}
	return (iter);
}

void	fract_render(t_mlx *fract)
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
			fract->c.r = ((double)x * (REAL_MAX - REAL_MIN) / WIDTH) + REAL_MIN;
			fract->c.i = ((double)y * (IMG_MAX - IMG_MIN) / HEIGHT) + IMG_MIN;
			iter = iteration(fract);
			put_pixel(&fract->img, x, y, get_color(iter, fract));
		}
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr,
		fract->img.img_ptr, 0, 0);
}
