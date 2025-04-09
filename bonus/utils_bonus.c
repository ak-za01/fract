/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 07:13:17 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/09 05:29:29 by anktiri          ###   ########.fr       */
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
	ft_print("╠════════════════ BUTTON MASHING GUIDE FOR FRACTAL WIZARDS ═\
═══════════════╣\n", 1);
	ft_print("║                                                           \
               ║\n", 1);
	ft_print("║  Mouse Scroll   Zoom in/out of fractal space              \
               ║\n", 1);
	ft_print("║  Arrow Keys     Navigate across the infinite void         \
               ║\n", 1);
	ft_print("║  [U-J]          Control how many calculations (before your\
               ║\n", 1);
	ft_print("║                 computer files for emotional distress)    \
               ║\n", 1);
	ft_print("║  \033[1;31m[R-F]          Add redness (perfect when fracta\
ls trigger rage)\033[1;37m         ║\n", 1);
	ft_print("║  \033[1;32m[T-G]          Adjust greenness (envy-inducing \
infinite loops)\033[1;37m          ║\n", 1);
	ft_print("║  \033[1;34m[Y-H]          Modify blueness (even math gets \
the blues sometimes)\033[1;37m     ║\n", 1);
	ft_print("║  [Q]            Reset fractal view to its original state  \
               ║\n", 1);
	ft_print("║                                                           \
               ║\n", 1);
	ft_print("╚═══════ CAUTION: EXCESSIVE FRACTALING MAY RESULT IN EXISTEN\
TIALISM ═══════╝\n", 1);
	ft_print("\033[0m\n", 1);
	exit(1);
}

void	message(void)
{
	ft_print("\033[1;37m\n", 1);
	ft_print("╔══════════════ FRACTOL: INFINITE PATTERNS, FINITE PATIENCE \
═══════════════╗\n", 1);
	ft_print("║                                                           \
               ║\n", 1);
	ft_print("║  Usage: ./fractol [choose your mathematical nightmare]    \
               ║\n", 1);
	ft_print("║                                                           \
               ║\n", 1);
	ft_print("║  Available fractals:                                      \
               ║\n", 1);
	ft_print("║    - mandelbrot     : The one that started it all         \
               ║\n", 1);
	ft_print("║    - julia          : Like Mandelbrot, but caffeinated    \
               ║\n", 1);
	ft_print("║    - burning_ship   : Chaos meets fire — dramatic visuals \
ahead          ║\n", 1);
	ft_print("║    - tricorn        : A complex reflection of complexity  \
               ║\n", 1);
	ft_print("║    - mandelbox      : A recursive cube of deep math though\
ts             ║\n", 1);
	ft_print("║                                                           \
               ║\n", 1);
	ft_print("║  Example: ./fractol mandelbrot                            \
               ║\n", 1);
	ft_print("║           Start with a classic before going full chaos    \
               ║\n", 1);
	ft_print("║                                                           \
               ║\n", 1);
	message_2();
}
