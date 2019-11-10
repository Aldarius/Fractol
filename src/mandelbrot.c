/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:57:06 by lminta            #+#    #+#             */
/*   Updated: 2019/07/09 21:34:13 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "frac_mods.h"

int			mandelbrot_test(t_complex c, int n, int power)
{
	t_complex	z;
	int			i;

	z.im = 0;
	z.re = 0;
	i = 0;
	while (i < n && z.im * z.im + z.re * z.re < 4)
	{
		z = c_sum(c_pow(z, abs(power)), c);
		i++;
	}
	return (i);
}

int			optimization(long double x, long double y)
{
	long double	roc;
	long double	ro;
	long double	fi;

	ro = (x - 1.0l / 4.0l) * (x - 1.0l / 4.0l) + y * y;
	fi = atan2l(y, x - 1.0l / 4.0l);
	roc = 1.0l / 2.0l - 1.0l / 2.0l * cosl(fi);
	roc *= roc;
	if (ro < roc)
		return (1);
	else
		return (0);
}

void		mandelbrot(void)
{
	if (g_color_mod(0, 0) == 1)
		colors_man(&man_thread_two);
	if (g_color_mod(0, 0) == 2)
		colors_man(&three_colors_man);
	if (g_color_mod(0, 0) == 3)
		colors_man(&multi_man);
}
