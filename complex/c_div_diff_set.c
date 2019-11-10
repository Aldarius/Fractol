/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_div_diff_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:17:35 by lminta            #+#    #+#             */
/*   Updated: 2019/06/27 21:24:18 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

t_complex	c_diff(t_complex a, t_complex b)
{
	return (c_sum(a, c_minus(b)));
}

t_complex	c_div(t_complex a, t_complex b)
{
	return (c_mult(a, c_conj(b)));
}

t_complex	c_pow(t_complex a, int n)
{
	t_complex	temp;
	int			i;

	i = 0;
	temp.re = 1;
	temp.im = 0;
	if (n < 0)
	{
		a = c_conj(a);
		n = -n;
	}
	while (i < n)
	{
		temp = c_mult(temp, a);
		i++;
	}
	return (temp);
}

t_complex	c_set(long double re, long double im)
{
	t_complex	temp;

	temp.re = re;
	temp.im = im;
	return (temp);
}
