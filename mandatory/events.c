/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:31:28 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/05 06:33:53 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	move_arrow(int key, t_mlx *fract)
{
	if (key == 123)
		fract->axis_x -= 0.5 * fract->zoom;
	else if (key == 124)
		fract->axis_x += 0.5 * fract->zoom;
	if (key == 125)
		fract->axis_y += 0.5 * fract->zoom;
	else if (key == 126)
		fract->axis_y -= 0.5 * fract->zoom;
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
		fract->iteration += 10;
	return (0);
}

int	change_color(int f,int key, t_mlx *fract)
{
	if (f == 1)
	{
		if (key == 15)
			fract->red++;
		else if (key == 17)
			fract->green++;
		else if (key == 16)
			fract->blue++;
	}
	else if (f == 0)
	{
		if (key == 3)
			fract->red--;
		else if (key == 5)
			fract->green--;
		else if (key == 4)
			fract->blue--;
	}
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
    else if (key == 38  || key == 32)
		iteration(key, fract);
	else if (key == 15 || key == 16 || key == 17)
		change_color(1, key, fract);
	else if (key == 3 || key == 4 || key == 5)
		change_color(0, key, fract);
	render(fract);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_mlx *fract)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fract->zoom *= 1.25;
	}
	else if (button == 5)
	{
		fract->zoom *= 0.75;
	}
	render(fract);
	return (0);
}
