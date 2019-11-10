/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelmods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:18:15 by lminta            #+#    #+#             */
/*   Updated: 2019/08/21 12:26:18 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "frac_mods.h"

void		*man_thread_two(void *snuffbox)
{
	int			i;
	int			j;
	t_move		mv;

	mv = *((t_move *)snuffbox);
	i = (WIN_Y / THREADS) * mv.thread - 1;
	while (++i < (WIN_Y / THREADS) * (mv.thread + 1) && (j = -1))
		while (++j < WIN_X)
		{
			if (mv.power == 2 &&
				optimization(j * mv.zoom + mv.rl, -i * mv.zoom + mv.ud))
				img_plot(j, i, g_end_c(fill_color(0, 0, 0), 0));
			else if (mandelbrot_test(c_set(j * mv.zoom + mv.rl,
					-i * mv.zoom + mv.ud), mv.n, mv.power) == mv.n)
				img_plot(j, i, g_end_c(fill_color(0, 0, 0), 0));
			else
				img_plot(j, i, g_color(fill_color(0, 0, 0), 0));
		}
	return (0);
}

void		*three_colors_man(void *snuffbox)
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
			if (mv.power == 2 &&
				optimization(j * mv.zoom + mv.rl, -i * mv.zoom + mv.ud))
				img_plot(j, i, fill_color(0, 0, 0));
			else if (mandelbrot_test(c_set(j * mv.zoom + mv.rl,
					-i * mv.zoom + mv.ud), mv.n, mv.power) == mv.n)
				img_plot(j, i, fill_color(0, 0, 0));
			else
				img_plot(j, i, sum_collors(g_color(grad, 0), grad,
			mandelbrot_test(c_set(j * mv.zoom + mv.rl, -i * mv.zoom + mv.ud),
						mv.n, mv.power)));
		}
	return (0);
}

void		*multi_man(void *snuffbox)
{
	int		i;
	int		j;
	t_move	mv;

	mv = *((t_move *)snuffbox);
	i = (WIN_Y / THREADS) * mv.thread - 1;
	while (++i < (WIN_Y / THREADS) * (mv.thread + 1) && (j = -1))
		while (++j < WIN_X)
		{
			if (mv.power == 2 &&
				optimization(j * mv.zoom + mv.rl, -i * mv.zoom + mv.ud))
				img_plot(j, i, fill_color(0, 0, 0));
			else if (mandelbrot_test(c_set(j * mv.zoom + mv.rl,
					-i * mv.zoom + mv.ud), mv.n, mv.power) == mv.n)
				img_plot(j, i, fill_color(0, 0, 0));
			else
				img_plot(j, i, n_color(mandelbrot_test(
						c_set(j * mv.zoom + mv.rl, -i * mv.zoom + mv.ud), mv.n,
						mv.power)));
		}
	return (0);
}

void		colors_man(void *(*mandelbrot_test)(void *))
{
	int			k;
	pthread_t	threads[THREADS];
	t_move		mv[THREADS];

	k = 0;
	while (k < THREADS)
	{
		mv[k] = g_mv(0, 0);
		mv[k].thread = k;
		pthread_create(&(threads[k]), NULL, mandelbrot_test, (void *)(&mv[k]));
		++k;
	}
	k = 0;
	while (k < THREADS)
	{
		pthread_join(threads[k], NULL);
		++k;
	}
}
