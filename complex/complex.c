/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 16:29:27 by lminta            #+#    #+#             */
/*   Updated: 2019/06/25 20:40:33 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

double		c_abs(t_complex num)
{
	return (sqrt(num.im * num.im + num.re * num.re));
}

t_complex	c_sum(t_complex a, t_complex b)
{
	t_complex temp;

	temp.re = a.re + b.re;
	temp.im = a.im + b.im;
	return (temp);
}

t_complex	c_minus(t_complex num)
{
	num.re = -num.re;
	num.im = -num.im;
	return (num);
}

t_complex	c_mult(t_complex a, t_complex b)
{
	t_complex temp;

	temp.re = a.re * b.re - a.im * b.im;
	temp.im = a.im * b.re + b.im * a.re;
	return (temp);
}

t_complex	c_conj(t_complex num)
{
	t_complex temp;

	temp.re = num.re / (num.re * num.re + num.im * num.im);
	temp.im = -num.im / (num.re * num.re + num.im * num.im);
	return (temp);
}
