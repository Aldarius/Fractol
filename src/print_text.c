/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:21:28 by lminta            #+#    #+#             */
/*   Updated: 2019/07/10 17:32:39 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_mod(void)
{
	t_color	temp;

	temp = fill_color(0, 0, 0);
	if (g_mod(0, 0) == 1)
		mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr, 10, 10,
		rgb_to_int(g_end_c(temp, 0)), "mandelbrot");
	if (g_mod(0, 0) == 2)
		mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr, 10, 10,
		rgb_to_int(g_end_c(temp, 0)), "julia");
	if (g_mod(0, 0) == 3)
		mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr, 10, 10,
		rgb_to_int(g_end_c(temp, 0)), "newton");
	if (g_color_mod(0, 0) == 1)
		mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr, 10, 30,
		rgb_to_int(g_end_c(temp, 0)), "two colors");
	if (g_color_mod(0, 0) == 2)
		mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr, 10, 30,
		rgb_to_int(g_end_c(temp, 0)), "three colors");
	if (g_color_mod(0, 0) == 3)
		mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr, 10, 30,
		rgb_to_int(g_end_c(temp, 0)), "multicolor");
}

void		print_help(void)
{
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr,
	10, g_win(0, 0).y - 250, rgb_to_int(g_end_c(fill_color(0, 0, 0), 0)),
	"You can use ARROWS for movement");
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr,
	10, g_win(0, 0).y - 230, rgb_to_int(g_end_c(fill_color(0, 0, 0), 0)),
	"12345 for different fractals and C to switch color mod");
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr,
	10, g_win(0, 0).y - 210, rgb_to_int(g_end_c(fill_color(0, 0, 0), 0)),
	"< change base color, > change additional color");
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr,
	10, g_win(0, 0).y - 190, rgb_to_int(g_end_c(fill_color(0, 0, 0), 0)),
	"Number of iterations buttons is +/-");
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr,
	10, g_win(0, 0).y - 170, rgb_to_int(g_end_c(fill_color(0, 0, 0), 0)),
	"Zooming buttons is +/- on numeric keypad");
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr,
	10, g_win(0, 0).y - 150, rgb_to_int(g_end_c(fill_color(0, 0, 0), 0)),
	"Press SPACE to reset position and ESC to exit");
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr,
	10, g_win(0, 0).y - 130, rgb_to_int(g_end_c(fill_color(0, 0, 0), 0)),
	"PU/PD for chenge power of fraktal");
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr,
	10, g_win(0, 0).y - 110, rgb_to_int(g_end_c(fill_color(0, 0, 0), 0)),
	"In julia mod you can pause and unpause changes whith P");
}

void		print_text(void)
{
	t_color	temp;

	temp = fill_color(0, 0, 0);
	print_mod();
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr, 10,
	g_win(0, 0).y - 30, rgb_to_int(g_end_c(temp, 0)), "Press H for help");
	if (g_help(0, 0))
		print_help();
}

int			g_help(int new_help, int flag)
{
	static int	current_mod = 0;

	if (flag)
		current_mod = new_help;
	return (current_mod);
}
