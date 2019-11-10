/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 21:50:16 by lminta            #+#    #+#             */
/*   Updated: 2019/06/28 19:44:30 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			g_mod(int new_mod, int flag)
{
	static int	current_mod = 1;

	if (flag)
		current_mod = new_mod;
	return (current_mod);
}

int			g_pause(int new_mod, int flag)
{
	static int	current_mod = 1;

	if (flag)
		current_mod = new_mod;
	return (current_mod);
}

t_complex	g_lastcoord(t_complex c, int flag)
{
	static t_complex	current_mod;

	if (flag)
		current_mod = c;
	return (current_mod);
}

int			g_color_mod(int new_mod, int flag)
{
	static int	current_mod = 1;

	if (flag)
		current_mod = new_mod;
	return (current_mod);
}

void		draw_frac(void)
{
	if (g_mod(0, 0) == 1)
		mandelbrot();
	if (g_mod(0, 0) == 2)
		julia();
	if (g_mod(0, 0) == 3)
		newton();
	mlx_put_image_to_window(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr,
	g_mlx(0, 0).img_ptr, 0, 0);
	print_text();
}
