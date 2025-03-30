/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 07:13:17 by anktiri           #+#    #+#             */
/*   Updated: 2025/03/30 10:12:30 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (n == 0)
		return (0);
	while (*s1 == *s2 && *s1 && n)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
	{
		while (*s)
			write(fd, s++, 1);
	}
}

void    message(void)
{
	ft_putstr_fd("\e[1;31m## error - incorrect syntax ##\n\n\e[0m", 1);
	ft_putstr_fd("\e[1;92m./fractol mandelbrot\n\e[0m", 1);
	ft_putstr_fd("\e[1;92m./fractol julia [real] [imaginary]\n\e[0m", 1);
	ft_putstr_fd("\e[1;92mThe range of those numbers are [-2 , 2]\n\e[0m", 1);
	exit (1);
}
