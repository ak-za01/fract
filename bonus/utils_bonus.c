/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 07:13:17 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/07 17:36:18 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol_bonus.h"

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

void	ft_print(char *s, int fd)
{
	if (s != NULL)
	{
		while (*s)
			write(fd, s++, 1);
	}
}

void	message_2(void)
{
	ft_print(" |----------------------- KEYBOARD ------------------------|\n",
		1);
	ft_print(" |                                                         |\n",
		1);
	ft_print(" | Press one of [U-J] keys to change iteration of fractal  |\n",
		1);
	ft_print(" | Use mouse scroll to zoom in and out of the fractal      |\n",
		1);
	ft_print(" | Press the arrow keys to change the viewpoint            |\n",
		1);
	ft_print(" |                                                         |\n",
		1);
	ft_print(" +---------------------------------------------------------+\n",
		1);
	ft_print("\n\033[0m", 1);
	exit(1);
}

void	message(void)
{
	ft_print("\n", 1);
	ft_print("\033[1;37m \
+------------------ Let me help you! ---------------------+\n",
		1);
	ft_print(" |                                                         |\n",
		1);
	ft_print(" | Usage: ./fractol [mandelbrot / julia / burning_ship     |\n",
		1);
	ft_print(" |                   tricorn / mandelbox]                  |\n",
		1);
	ft_print(" |                                                         |\n",
		1);
	ft_print(" | e.g: ./fractol mandelbrot                               |\n",
		1);
	ft_print(" |                                                         |\n",
		1);
	message_2();
}
