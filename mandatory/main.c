/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:24:43 by anktiri           #+#    #+#             */
/*   Updated: 2025/03/30 14:43:12 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	check_input(char **av, t_mlx *fract)
{
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
		init_fract(&fract, av[1]);
	else if (ft_strncmp(av[1], "julia", 5) == 0)
		ft_putstr_fd("user want julia set\n", 1);
	else
		message();
}

int main(int ac, char **av)
{
	t_mlx	*fract;

    if (ac < 2 || ac > 4)
        message();
	else
		check_input(av, fract);
}
