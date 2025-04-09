/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 01:09:30 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/09 05:19:29 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol_bonus.h"

static double	ft_atoi(char *str, int *i, int *sign)
{
	double	result;

	*sign = 1;
	result = 0;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9' && str[*i])
	{
		result = result * 10 + str[*i] - '0';
		if (result > 3 || result * *sign < -3)
			return (3);
		(*i)++;
	}
	return (result);
}

static double	decimal_part(char *str, int *i)
{
	double	decimal;
	double	result;

	result = 0.0;
	decimal = 1;
	while (str[*i] >= '0' && str[*i] <= '9' && str[*i])
	{
		decimal /= 10;
		result = result + (str[*i] - '0') * decimal;
		(*i)++;
	}
	if (str[*i])
		return (3);
	return (result);
}

static double	ft_atod(char *str)
{
	int		i;
	int		sign;
	double	result;

	i = 0;
	result = 0.0;
	result = ft_atoi(str, &i, &sign);
	if (i == 0 && str[i] == '.')
		return (3);
	else if (str[i] == '.' && (str[i + 1]))
		i++;
	result += decimal_part(str, &i);
	if (result > 2.0 || result * sign < -2.0)
		return (3);
	return (result * sign);
}

void	julia_error(void)
{
	ft_print("\033[1;31m╔═════════════════════════════════════════════════════════════\
═════════╗\n", 1);
	ft_print("\033[1;31m║  ERROR: Insufficient arguments provided.                    \
         ║\n", 1);
	ft_print("\033[1;31m║                                                             \
         ║\n", 1);
	ft_print("\033[1;31m║  Julia fractal requires both real and imaginary components. \
         ║\n", 1);
	ft_print("\033[1;31m║                                                             \
         ║\n", 1);
	ft_print("\033[1;31m║  Usage: ./fractol julia <real> <imaginary>                  \
         ║\n", 1);
	ft_print("\033[1;31m║  Note: Both values must be within the range\
 -2.0 to 2.0              ║\n",
		1);
	ft_print("\033[1;31m╚═════════════════════════════════════════════════════════════\
═════════╝\033[0m\n",
		1);
	exit(1);
}

int	handle_arg(int ac, char **av, t_mlx *fract)
{
	if (ac < 4)
		julia_error();
	fract->julia_c.r = ft_atod(av[2]);
	fract->julia_c.i = ft_atod(av[3]);
	if (fract->julia_c.r > 2.0 || fract->julia_c.r < -2.0
		|| fract->julia_c.i > 2.0 || fract->julia_c.i < -2.0)
	{
		ft_print("\033[1;31m╔═════════════════════════════════════════════════════════\
═════════════╗\n",
			1);
		ft_print("\033[1;31m║  ERROR: Invalid Julia fractal parameters.               \
             ║\n",
			1);
		ft_print("\033[1;31m║                                                         \
             ║\n",
			1);
		ft_print("\033[1;31m║  The real and imaginary values must be within the range\
 -2.0 to 2.0. ║\n",
			1);
		ft_print("\033[1;31m╚═════════════════════════════════════════════════════════\
═════════════╝\033[0m\n",
			1);
		exit(1);
	}
	return (0);
}
