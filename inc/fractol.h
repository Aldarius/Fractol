/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 16:07:43 by lminta            #+#    #+#             */
/*   Updated: 2019/07/15 15:41:37 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_fractol_mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

void		print_text(void);
void		draw_frac(void);
int			g_mod(int new_mod, int flag);
int			g_help(int new_help, int flag);
void		mandelbrot(void);
void		julia(void);
int			cam_fractol(int keycode);
int			g_color_mod(int new_mod, int flag);
void		set_init_position(void);
int			zoom(int keycode, int x, int y);
t_complex	g_lastcoord(t_complex c, int flag);
int			g_pause(int new_mod, int flag);
int			mouse_move(int x, int y);
void		newton(void);
void		check_exit(int keycode);

#endif
