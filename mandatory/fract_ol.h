/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:23:53 by anktiri           #+#    #+#             */
/*   Updated: 2025/03/30 14:43:24 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

// # include "../include/MLX42/include/MLX42/MLX42.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 900
# define HEIGHT 700
# define IMG_MAX 2
# define IMG_MIN -2
# define REAL_MAX 2
# define REAL_MIN -2

typedef struct s_image
{
	void	*img_ptr;
	void	*pixel_ptr;
	int		bitspp;
	int		line_len;
}	t_image;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	img;
} t_mlx;

int ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr_fd(char *s, int fd);
void    message(void);
void	init_fract(t_mlx *fract, char *name);


#endif