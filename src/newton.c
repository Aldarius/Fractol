/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 18:47:28 by lminta            #+#    #+#             */
/*   Updated: 2019/08/16 20:13:27 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "frac_mods.h"

int		newton_test(t_complex z, int n, int power)
{
	t_complex	c;
	t_complex	cn;
	int			i;

	c = c_set(-1, 0);
	cn = c_set(n, 0);
	i = 0;
	while (i < n && z.im * z.im + z.re * z.re < 4)
	{
		z = c_sum(z, c_div(c_sum(c_pow(z, power), c), c_mult(cn,
		c_pow(z, power - 1))));
		i++;
	}
	return (i);
}

void	newton(void)
{
	if (g_color_mod(0, 0) == 1)
		colors_man(&two_colors_new);
	if (g_color_mod(0, 0) == 2)
		colors_man(&three_colors_new);
	if (g_color_mod(0, 0) == 3)
		colors_man(&multi_new);
}
