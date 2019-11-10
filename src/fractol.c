/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 19:48:18 by lminta            #+#    #+#             */
/*   Updated: 2019/07/15 15:42:15 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		press_x(void)
{
	t_mlx	mlx;

	mlx = g_mlx(0, 0);
	free(mlx.image);
	exit(0);
}

void			check_exit(int keycode)
{
	t_mlx	mlx;

	mlx = g_mlx(0, 0);
	if (keycode == 53)
	{
		free(mlx.image);
		exit(0);
	}
}

int				main(int argc, char **argv)
{
	t_move	mv;

	if (argc < 2 || argc > 3 || argv[1][0] < '0' || argv[1][0] > '3')
	{
		write(1, "usage: fractol [1,2,3] <power>\n", 31);
		return (0);
	}
	ft_mlx_init(WIN_X, WIN_Y, "ebobo");
	g_mod(atoi(argv[1]), 1);
	set_init_position();
	mv = g_mv(0, 0);
	if (argc == 3)
		mv.power = atoi(argv[2]);
	g_mv(&mv, 3);
	draw_frac();
	mlx_hook(g_mlx(0, 0).win_ptr, 2, 0, &cam_fractol, 0);
	mlx_hook(g_mlx(0, 0).win_ptr, 4, 0, &zoom, 0);
	mlx_hook(g_mlx(0, 0).win_ptr, 6, 0, &mouse_move, 0);
	mlx_hook(g_mlx(0, 0).win_ptr, 17, 0, &press_x, 0);
	mlx_loop(g_mlx(0, 0).mlx_ptr);
	return (0);
}
