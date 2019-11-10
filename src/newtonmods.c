/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtonmods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 18:47:42 by lminta            #+#    #+#             */
/*   Updated: 2019/07/10 17:29:38 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "frac_mods.h"

void		*two_colors_new(void *snuffbox)
{
	int		i;
	int		j;
	t_move	mv;

	mv = *((t_move *)snuffbox);
	i = (WIN_Y / THREADS) * mv.thread - 1;
	while (++i < (WIN_Y / THREADS) * (mv.thread + 1) && (j = -1))
		while (++j < WIN_X)
		{
			if (newton_test(c_set(j * mv.zoom + mv.rl,
			-i * mv.zoom + mv.ud), mv.n, mv.power) == mv.n)
				img_plot(j, i, g_end_c(fill_color(0, 0, 0), 0));
			else
				img_plot(j, i, g_color(fill_color(0, 0, 0), 0));
		}
	return (0);
}

void		*three_colors_new(void *snuffbox)
{
	int		i;
	int		j;
	t_move	mv;
	t_color	grad;

	mv = *((t_move *)snuffbox);
	i = (WIN_Y / THREADS) * mv.thread - 1;
	grad = fill_color(0, 0, 0);
	grad = gradient(g_color(grad, 0), g_end_c(grad, 0), mv.n);
	while (++i < (WIN_Y / THREADS) * (mv.thread + 1) && (j = -1))
		while (++j < WIN_X)
		{
			if (newton_test(c_set(j * mv.zoom + mv.rl,
			-i * mv.zoom + mv.ud), mv.n, mv.power) == mv.n)
				img_plot(j, i, fill_color(0, 0, 0));
			else
				img_plot(j, i, sum_collors(g_color(grad, 0), grad, newton_test(
				c_set(j * mv.zoom + mv.rl, -i * mv.zoom + mv.ud),
				mv.n, mv.power)));
		}
	return (0);
}

void		*multi_new(void *snuffbox)
{
	int		i;
	int		j;
	t_move	mv;

	mv = *((t_move *)snuffbox);
	i = (WIN_Y / THREADS) * mv.thread - 1;
	while (++i < (WIN_Y / THREADS) * (mv.thread + 1) && (j = -1))
		while (++j < WIN_X)
		{
			if (newton_test(c_set(j * mv.zoom + mv.rl,
					-i * mv.zoom + mv.ud), mv.n, mv.power) == mv.n)
				img_plot(j, i, fill_color(0, 0, 0));
			else
				img_plot(j, i, n_color(newton_test(
						c_set(j * mv.zoom + mv.rl, -i * mv.zoom + mv.ud),
						mv.n, mv.power)));
		}
	return (0);
}
