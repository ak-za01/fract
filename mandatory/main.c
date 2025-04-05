/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:24:43 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/05 04:57:26 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	check_input(int ac ,char **av, t_mlx *fract)
{
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
	{
		fract->title = av[1];
		init_fract(fract);
		mandelbrot_render(fract);
	}
	else if (ft_strncmp(av[1], "julia", 5) == 0)
	{
		if (handle_arg(ac, av, fract) == 1)
			message();
		fract->title = av[1];
		init_fract(fract);
		julia_render(fract);
	}
	else
		message();
	mlx_key_hook(fract->win_ptr, handle_key, fract);
	mlx_hook(fract->win_ptr, 17, 0, close_window, fract);
	mlx_mouse_hook(fract->win_ptr, handle_mouse, fract);
	mlx_loop(fract->mlx_ptr);
}

void	ll(void)
{
	system("leaks -q fractol");
}

int	main(int ac, char **av)
{
	t_mlx	fract;

	atexit(ll);
	if (ac < 2 || ac > 4)
		message();
	else
		check_input(ac, av, &fract);
	return (0);
}
