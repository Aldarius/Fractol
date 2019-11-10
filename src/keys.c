/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:06:06 by lminta            #+#    #+#             */
/*   Updated: 2019/07/12 14:27:09 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		change_color(int keycode)
{
	if (keycode == 18)
		g_mod(1, 1);
	else if (keycode == 19)
		g_mod(2, 1);
	else if (keycode == 20)
		g_mod(3, 1);
	else if (keycode == 21)
		g_mod(4, 1);
	else if (keycode == 23)
		g_mod(5, 1);
	else if (keycode == 43)
		new_color();
	else if (keycode == 47)
		end_color();
	else if (keycode == 4)
	{
		if (g_help(0, 0))
			g_help(0, 1);
		else
			g_help(1, 1);
	}
	else
		check_exit(keycode);
}

static t_move	iter(int keycode)
{
	t_move	mv;

	mv = g_mv(0, 0);
	if (keycode == 27)
		mv.n -= 2;
	else if (keycode == 24)
		mv.n += 2;
	else if (keycode == 49)
		mv = g_mv(0, 2);
	else if (keycode == 8)
	{
		g_color_mod(g_color_mod(0, 0) + 1, 1);
		if (g_color_mod(0, 0) == 4)
			g_color_mod(1, 1);
	}
	else if (keycode == 35 && g_mod(0, 0) == 2)
	{
		if (g_pause(0, 0))
			g_pause(0, 1);
		else
			g_pause(1, 1);
	}
	else
		change_color(keycode);
	return (mv);
}

int				cam_fractol(int keycode)
{
	t_move	mv;

	mv = g_mv(0, 0);
	if (keycode == 126)
		mv.ud += 25 * mv.zoom;
	else if (keycode == 125)
		mv.ud -= 25 * mv.zoom;
	else if (keycode == 124)
		mv.rl += 25 * mv.zoom;
	else if (keycode == 123)
		mv.rl -= 25 * mv.zoom;
	else if (keycode == 116)
		mv.power += 1;
	else if (keycode == 121)
		mv.power -= 1;
	else
		mv = iter(keycode);
	g_mv(&mv, 1);
	if ((keycode >= 18 && keycode <= 21) || keycode == 23)
		set_init_position();
	draw_frac();
	return (0);
}

int				zoom(int keycode, int x, int y)
{
	t_move	mv;
	double	a;

	a = 1.5;
	mv = g_mv(0, 0);
	if (keycode == 4)
	{
		mv.rl += (mv.zoom * x * (1 - 1 / a));
		mv.ud += (mv.zoom * y * (1 / a - 1));
		mv.zoom /= a;
	}
	else if (keycode == 5)
	{
		mv.rl += (mv.zoom * x * (1 - a));
		mv.ud += (mv.zoom * y * (a - 1));
		mv.zoom *= a;
	}
	g_mv(&mv, 1);
	draw_frac();
	return (0);
}

int				mouse_move(int x, int y)
{
	t_move	mv;

	if (g_mod(0, 0) == 2 && !g_pause(0, 0))
	{
		mv = g_mv(0, 0);
		g_lastcoord(c_set(x * mv.zoom + mv.rl, -y * mv.zoom + mv.ud), 1);
		draw_frac();
	}
	return (0);
}
