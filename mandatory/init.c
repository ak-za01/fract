/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:42:50 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/05 06:21:20 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	ft_error(void)
{
	ft_print("malloc failled", 1);
	exit (1);
}

static void	init(t_mlx *fract)
{
	fract->iteration = 100;
	fract->axis_x = 0.0;
	fract->axis_y = 0.0;
	fract->zoom = 1.0;
}

void	init_fract(t_mlx *fract)
{
	init(fract);
	fract->mlx_ptr = mlx_init();
	if (!fract->mlx_ptr)
		return (ft_error());
	fract->win_ptr = mlx_new_window(fract->mlx_ptr,
			WIDTH, HEIGHT, fract->title);
	if (!fract->win_ptr)
	{
		free(fract->mlx_ptr);
		return (ft_error());
	}
	fract->img.img_ptr = mlx_new_image(fract->mlx_ptr, WIDTH, HEIGHT);
	if (!fract->img.img_ptr)
	{
		mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
		free(fract->mlx_ptr);
		return (ft_error());
	}
	fract->img.pixel_ptr = mlx_get_data_addr(fract->img.img_ptr,
			&fract->img.bitspp, &fract->img.line_len, &fract->img.endian);
}
