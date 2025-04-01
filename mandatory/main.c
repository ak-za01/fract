/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akza <akza@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:24:43 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/01 03:14:11 by akza             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	check_input(char **av, t_mlx *fract)
{
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
	{
		fract->title = av[1];
		init_fract(fract);
		fract_render(fract);
	}
	else if (ft_strncmp(av[1], "julia", 5) == 0)
		ft_putstr_fd("user want julia set\n", 1);
	else
		message();
}

int	main(int ac, char **av)
{
	t_mlx	fract;

	if (ac < 2 || ac > 4)
		message();
	else
	{
		check_input(av, &fract);
	}
	mlx_loop(fract.mlx_ptr);
}
