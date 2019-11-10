/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_mlx.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:33:52 by lminta            #+#    #+#             */
/*   Updated: 2019/08/21 11:57:19 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_MLX_H
# define FT_FRACTOL_MLX_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include "complex.h"

# define WIN_X		1200
# define WIN_Y		1200
# define THREADS	8

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

typedef struct	s_xy
{
	double		x;
	double		y;
}				t_xy;

typedef struct	s_move
{
	long double	ud;
	long double	rl;
	long double	zoom;
	int			n;
	int			power;
	int			thread;
}				t_move;

typedef struct	s_borders
{
	double		xmin;
	double		ymin;
	double		xmax;
	double		ymax;

}				t_borders;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		*image;
}				t_mlx;

void			img_plot(int x, int y, t_color cl);
void			ft_mlx_init(int a, int b, char *str);
t_color			fill_color(double red, double green, double blue);
t_borders		fill_borders(double xmin,
double ymin, double xmax, double ymax);
t_color			g_color(t_color color, int flag);
t_move			g_mv(t_move *mv, int flag);
t_mlx			g_mlx(t_mlx *mlx, int flag);
t_xy			g_win(t_xy *win, int flag);
int				rgb_to_int(t_color cl);
t_color			gradient(t_color color1, t_color color2, double length);
void			new_color(void);
void			end_color(void);
t_color			g_end_c(t_color color, int flag);
t_color			sum_collors(t_color color, t_color grad, int count);
t_color			n_color(int n);

#endif
