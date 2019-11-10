/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:57:06 by lminta            #+#    #+#             */
/*   Updated: 2019/07/10 12:28:41 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "frac_mods.h"

int			julia_test(t_complex z, t_complex c, int n, int power)
{
	int	i;

	i = 0;
	while (i < n && z.im * z.im + z.re * z.re < 4)
	{
		z = c_sum(c_pow(z, power), c);
		i++;
	}
	return (i);
}

void		set_init_position(void)
{
	t_move		mv;
	t_borders	br;
	double		ax;
	double		ay;

	mv = g_mv(0, 0);
	if (g_mod(0, 0) == 1)
		br = fill_borders(-2.5, -1, 1, 1);
	if (g_mod(0, 0) == 2)
		br = fill_borders(-1.5, -1, 1.5, 1);
	if (g_mod(0, 0) == 3)
		br = fill_borders(-1.5, -1, 1.5, 1);
	mv.rl = br.xmin;
	mv.ud = br.ymax;
	mv.n = 20;
	ax = (br.xmax - br.xmin) / g_win(0, 0).x;
	ay = (br.ymax - br.ymin) / g_win(0, 0).y;
	mv.zoom = ax > ay ? ax : ay;
	g_mv(&mv, 3);
	g_lastcoord(c_set(-0.8, 0.156), 1);
}

void		julia(void)
{
	if (g_color_mod(0, 0) == 1)
		colors_man(&two_colors_jul);
	if (g_color_mod(0, 0) == 2)
		colors_man(&three_colors_jul);
	if (g_color_mod(0, 0) == 3)
		colors_man(&multi_jul);
}
