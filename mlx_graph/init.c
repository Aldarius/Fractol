/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:30:54 by lminta            #+#    #+#             */
/*   Updated: 2019/10/18 15:52:48 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol_mlx.h"

static void	ptr_init(int a, int b, char *str)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, a, b, str);
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, a, b);
	mlx.image = mlx_get_data_addr(mlx.img_ptr, &(mlx.bits_per_pixel),
	&(mlx.size_line), &(mlx.endian));
	g_mlx(&mlx, 1);
}

void		ft_mlx_init(int a, int b, char *str)
{
	t_move	mv;
	t_xy	win;

	ptr_init(a, b, str);
	g_color(fill_color(255, 255, 255), 1);
	g_end_c(fill_color(0, 0, 0), 1);
	mv.ud = 0;
	mv.rl = 0;
	mv.zoom = 1;
	mv.n = 1;
	mv.power = 2;
	g_mv(&mv, 1);
	win.x = a;
	win.y = b;
	g_win(&win, 1);
}

void		img_plot(int x, int y, t_color cl)
{
	int		i;
	t_mlx	mlx;

	mlx = g_mlx(0, 0);
	if (x > g_win(0, 0).x || y > g_win(0, 0).y || x < 0 || y < 0)
		return ;
	i = x * mlx.bits_per_pixel / 8 + y * mlx.size_line;
	mlx.image[i++] = (int)(cl.b);
	mlx.image[i++] = (int)(cl.g);
	mlx.image[i] = (int)(cl.r);
	g_mlx(&mlx, 1);
}
