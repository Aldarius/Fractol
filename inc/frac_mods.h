/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mods.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:19:17 by lminta            #+#    #+#             */
/*   Updated: 2019/07/09 22:06:36 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAC_MODS_H
# define FRAC_MODS_H

void	colors_man(void *(*mandelbrot_test)(void *));
void	*three_colors_man(void *snuffbox);
void	*multi_man(void *snuffbox);
void	*two_colors_jul(void *snuffbox);
void	*three_colors_jul(void *snuffbox);
void	*multi_jul(void *snuffbox);
int		newton_test(t_complex z, int n, int power);
int		mandelbrot_test(t_complex c, int n, int power);
int		julia_test(t_complex z, t_complex c, int n, int power);
void	*multi_new(void *snuffbox);
void	*three_colors_new(void *snuffbox);
void	*two_colors_new(void *snuffboxd);
void	*man_thread_two(void *snuffbox);
int		optimization(long double x, long double y);

#endif
