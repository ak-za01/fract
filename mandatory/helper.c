/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 01:09:30 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/07 06:14:01 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	ft_atoi(char *str, int *i, int *sign)
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
	if (str[i] == '.')
		i++;
	result += decimal_part(str, &i);
	if (result >= 2 || result * sign <= -2)
		return (3);
	return (result * sign);
}

int	handle_arg(int ac, char **av, t_mlx *fract)
{
	if (ac < 4)
		message();
	fract->julia_c.r = ft_atod(av[2]);
	fract->julia_c.i = ft_atod(av[3]);
	if (fract->julia_c.r > 2.0 || fract->julia_c.i > 2.0)
	{
		ft_print("\033[1;31mInvalid input for Julia fractal.\n\033[0m", 1);
		return (1);
	}
	return (0);
}
