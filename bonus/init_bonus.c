/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:42:50 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/07 17:35:56 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol_bonus.h"

static void	ft_error(void)
{
	ft_print("malloc failled", 1);
	exit(1);
}

static void	init(t_mlx *fract)
{
	fract->iteration = 200;
	fract->axis_x = 0.0;
	fract->axis_y = 0.0;
	fract->zoom = 0.25;
}

void	init_fract(t_mlx *fract, char *title)
{
	init(fract);
	fract->mlx_ptr = mlx_init();
	if (!fract->mlx_ptr)
		return (ft_error());
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, WIDTH, HEIGHT,
			title);
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

int	change_color(int f, int key, t_mlx *fract)
{
	if (f == 1)
	{
		if (key == 15)
			fract->red += 20;
		else if (key == 17)
			fract->green += 20;
		else if (key == 16)
			fract->blue += 20;
	}
	else if (f == 0)
	{
		if (key == 3)
			fract->red -= 20;
		else if (key == 5)
			fract->green -= 20;
		else if (key == 4)
			fract->blue -= 20;
		if (fract->red < 0)
			fract->red = 0;
		else if (fract->green < 0)
			fract->green = 0;
		else if (fract->blue < 0)
			fract->blue = 0;
	}
	return (0);
}

int	close_window(t_mlx *fract)
{
	mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	free(fract->mlx_ptr);
	exit(0);
}
