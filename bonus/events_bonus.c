/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:31:28 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/07 11:20:07 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol_bonus.h"

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
		fract->iteration += 50;
	return (0);
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
	else if (key == 15 || key == 16 || key == 17)
		change_color(1, key, fract);
	else if (key == 3 || key == 4 || key == 5)
		change_color(0, key, fract);
	else if (key == 12)
		reset(fract);
	render(fract);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_mlx *data)
{
	double	x_tmp;
	double	y_tmp;

	x_tmp = map_x(x, data);
	y_tmp = map_y(y, data);
	if (button == 4 || button == 5)
	{
		if (button == 5)
			data->zoom *= 1.2;
		else
			data->zoom *= 0.7;
		data->axis_x += x_tmp - map_x(x, data);
		data->axis_y += y_tmp - map_y(y, data);
		render(data);
	}
	return (0);
}
