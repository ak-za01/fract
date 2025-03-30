/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:42:50 by anktiri           #+#    #+#             */
/*   Updated: 2025/03/30 14:43:15 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	malloc_error()
{
	ft_putstr_fd("malloc failled", 1);
	exit (1);
}

void	init_fract(t_mlx *fract, char *name)
{
	fract->mlx_ptr = mlx_init();
	if (!fract->mlx_ptr)
		malloc_error();
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, WIDTH, HEIGHT, name);
	if (!fract->win_ptr)
	{
		free(fract->mlx_ptr);
		malloc_error();
	}
	fract->img.img_ptr = mlx_new_image(fract->mlx_ptr, WIDTH, HEIGHT);
	if (!fract->img.img_ptr)
	{
		mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
		free(fract->mlx_ptr);
		malloc_error();
	}
	fract->img.img_ptr = mlx_get_data_addr(fract->img.img_ptr, &fract->img.bitspp, &fract->img.line_len, NULL);
	//	event_init(fractal);//TODO
	//	data_init(fractal);//TODO
}