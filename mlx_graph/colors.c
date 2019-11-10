/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:30:46 by lminta            #+#    #+#             */
/*   Updated: 2019/07/10 17:27:41 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color		n_color(int n)
{
	t_color	temp;

	temp = fill_color(0, 0, 0);
	if (n % 7 == 6)
		temp = fill_color(255, 0, 0);
	else if (n % 7 == 5)
		temp = fill_color(0, 255, 0);
	else if (n % 7 == 4)
		temp = fill_color(0, 0, 255);
	else if (n % 7 == 3)
		temp = fill_color(255, 255, 0);
	else if (n % 7 == 2)
		temp = fill_color(255, 0, 255);
	else if (n % 7 == 1)
		temp = fill_color(0, 255, 255);
	else if (n % 7 == 0)
		temp = fill_color(255, 255, 255);
	if (g_end_c(temp, 0).r == temp.r && g_end_c(temp, 0).g == temp.g
	&& g_end_c(temp, 0).b == temp.b)
		new_color();
	return (temp);
}

void		new_color(void)
{
	t_color	temp;

	temp = fill_color(0, 0, 0);
	if (g_color(temp, 0).r && g_color(temp, 0).g && g_color(temp, 0).b)
		g_color(fill_color(255, 0, 0), 1);
	else if (g_color(temp, 0).r && !g_color(temp, 0).g && !g_color(temp, 0).b)
		g_color(fill_color(0, 255, 0), 1);
	else if (!g_color(temp, 0).r && g_color(temp, 0).g && !g_color(temp, 0).b)
		g_color(fill_color(0, 0, 255), 1);
	else if (!g_color(temp, 0).r && !g_color(temp, 0).g && g_color(temp, 0).b)
		g_color(fill_color(255, 255, 0), 1);
	else if (g_color(temp, 0).r && g_color(temp, 0).g && !g_color(temp, 0).b)
		g_color(fill_color(255, 0, 255), 1);
	else if (g_color(temp, 0).r && !g_color(temp, 0).g && g_color(temp, 0).b)
		g_color(fill_color(0, 255, 255), 1);
	else if (!g_color(temp, 0).r && g_color(temp, 0).g && g_color(temp, 0).b)
		g_color(fill_color(0, 0, 0), 1);
	else if (!g_color(temp, 0).r && !g_color(temp, 0).g && !g_color(temp, 0).b)
		g_color(fill_color(255, 255, 255), 1);
	if (g_end_c(temp, 0).r == g_color(temp, 0).r && g_end_c(temp, 0).g ==
	g_color(temp, 0).g && g_end_c(temp, 0).b == g_color(temp, 0).b)
		new_color();
}

void		end_color(void)
{
	t_color	temp;

	temp = fill_color(0, 0, 0);
	if (g_end_c(temp, 0).r && g_end_c(temp, 0).g && g_end_c(temp, 0).b)
		g_end_c(fill_color(255, 0, 0), 1);
	else if (g_end_c(temp, 0).r && !g_end_c(temp, 0).g && !g_end_c(temp, 0).b)
		g_end_c(fill_color(0, 255, 0), 1);
	else if (!g_end_c(temp, 0).r && g_end_c(temp, 0).g && !g_end_c(temp, 0).b)
		g_end_c(fill_color(0, 0, 255), 1);
	else if (!g_end_c(temp, 0).r && !g_end_c(temp, 0).g && g_end_c(temp, 0).b)
		g_end_c(fill_color(255, 255, 0), 1);
	else if (g_end_c(temp, 0).r && g_end_c(temp, 0).g && !g_end_c(temp, 0).b)
		g_end_c(fill_color(255, 0, 255), 1);
	else if (g_end_c(temp, 0).r && !g_end_c(temp, 0).g && g_end_c(temp, 0).b)
		g_end_c(fill_color(0, 255, 255), 1);
	else if (!g_end_c(temp, 0).r && g_end_c(temp, 0).g && g_end_c(temp, 0).b)
		g_end_c(fill_color(0, 0, 0), 1);
	else if (!g_end_c(temp, 0).r && !g_end_c(temp, 0).g && !g_end_c(temp, 0).b)
		g_end_c(fill_color(255, 255, 255), 1);
	if (g_end_c(temp, 0).r == g_color(temp, 0).r && g_end_c(temp, 0).g ==
	g_color(temp, 0).g && g_end_c(temp, 0).b == g_color(temp, 0).b)
		end_color();
}

t_color		gradient(t_color color1, t_color color2, double length)
{
	t_color	grad;

	if (!length)
		return (color2);
	grad.r = (color2.r - color1.r) / length;
	grad.g = (color2.g - color1.g) / length;
	grad.b = (color2.b - color1.b) / length;
	return (grad);
}

t_color		sum_collors(t_color color, t_color grad, int count)
{
	t_color	result;

	if (!grad.r && !grad.g && !grad.b)
		return (color);
	result.r = color.r + grad.r * count;
	result.g = color.g + grad.g * count;
	result.b = color.b + grad.b * count;
	return (result);
}
