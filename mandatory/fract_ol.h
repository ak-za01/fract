/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:23:53 by anktiri           #+#    #+#             */
/*   Updated: 2025/04/09 06:59:27 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../mlx/mlx.h"
# include <math.h>
// # include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 600
# define HEIGHT 600
# define IMG_MAX 2
# define IMG_MIN -2
# define REAL_MAX 2
# define REAL_MIN -2

//	COLORS
# define BLACK 0x000000 // RGB(0, 0, 0)
# define WHITE 0xFFFFFF // RGB(255, 255, 255)

typedef struct s_image
{
	void			*img_ptr;
	void			*pixel_ptr;
	int				bitspp;
	int				line_len;
	int				endian;
}					t_image;

typedef struct s_complex
{
	double			r;
	double			i;
}					t_complex;

typedef struct s_mlx
{
	char			*title;
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			img;
	t_complex		c;
	t_complex		z;
	t_complex		julia_c;
	double			iteration;
	double			axis_x;
	double			axis_y;
	double			zoom;
	int				flag;
	unsigned int	color;
}					t_mlx;

int					ft_strncmp(char *s1, char *s2, int n);
void				ft_print(char *s, int fd);
void				message(void);
void				init_fract(t_mlx *fract);
int					close_window(t_mlx *fract);
int					handle_key(int key, t_mlx *fract);
int					handle_mouse(int button, int x, int y, t_mlx *fract);
int					handle_arg(int ac, char **av, t_mlx *fract);
void				render(t_mlx *fract);
double				map_x(int x, t_mlx *data);
double				map_y(int y, t_mlx *data);
void				reset_fract(t_mlx *fract);

#endif