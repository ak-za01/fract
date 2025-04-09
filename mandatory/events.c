/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:31:28 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/09 05:51:17 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	move_arrow(int key, t_mlx *fract)
{
	if (key == 123)
		fract->axis_x -= 0.1 / fract->zoom;
	else if (key == 124)
		fract->axis_x += 0.1 / fract->zoom;
	if (key == 125)
		fract->axis_y += 0.1 / fract->zoom;
	else if (key == 126)
		fract->axis_y -= 0.1 / fract->zoom;
	return (0);
}

static int	iteration(int key, t_mlx *fract)
{
	if (key == 38 && fract->iteration > 10)
	{
		fract->iteration -= 50;
		if (fract->iteration < 10)
			fract->iteration = 10;
	}
	else if (key == 32)
		fract->iteration += 50;
	return (0);
}

int	close_window(t_mlx *fract)
{
	mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	free(fract->mlx_ptr);
	exit(0);
}

int	handle_key(int key, t_mlx *fract)
{
	if (key == 53)
		close_window(fract);
	else if (key == 123 || key == 124)
		move_arrow(key, fract);
	else if (key == 125 || key == 126)
		move_arrow(key, fract);
	else if (key == 38 || key == 32)
		iteration(key, fract);
	else if (key == 12)
		reset_fract(fract);
	render(fract);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_mlx *fract)
{
	(void)x;
	(void)y;
	if (button == 5)
		fract->zoom *= 1.8;
	else
		fract->zoom *= 0.8;
	render(fract);
	return (0);
}
