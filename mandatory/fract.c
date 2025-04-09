/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:24:43 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/09 07:20:29 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	handle_input(int ac, char **av, t_mlx *fract)
{
	if (ac < 2 || ac > 4)
		return (1);
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
		fract->flag = ((fract->title = av[1]), 0);
	else if (ft_strncmp(av[1], "julia", 5) == 0)
	{
		if (handle_arg(ac, av, fract) == 1)
			message();
		fract->flag = ((fract->title = av[1]), 1);
	}
	else
		message();
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	fract;

	if (handle_input(ac, av, &fract))
		message();
	init_fract(&fract);
	render(&fract);
	mlx_key_hook(fract.win_ptr, handle_key, &fract);
	mlx_hook(fract.win_ptr, 17, 0, close_window, &fract);
	mlx_mouse_hook(fract.win_ptr, handle_mouse, &fract);
	mlx_loop(fract.mlx_ptr);
}
