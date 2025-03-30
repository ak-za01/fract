/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:43:41 by anktiri           #+#    #+#             */
/*   Updated: 2025/03/30 14:47:39 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	handle_pixel(int x, int y, t_mlx *fract)
{
	
}

void    fract_render(t_mlx *fract)
{
	int	x;
	int	y;
    
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			hand_pixel(x, y, fract);
		}
	}
}