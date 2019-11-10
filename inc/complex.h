/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 16:24:02 by lminta            #+#    #+#             */
/*   Updated: 2019/06/26 13:35:18 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include <math.h>
# include <stdlib.h>

typedef struct	s_complex
{
	double	re;
	double	im;
}				t_complex;

double			c_abs(t_complex num);
t_complex		c_sum(t_complex a, t_complex b);
t_complex		c_minus(t_complex num);
t_complex		c_mult(t_complex a, t_complex b);
t_complex		c_conj(t_complex num);
t_complex		c_diff(t_complex a, t_complex b);
t_complex		c_div(t_complex a, t_complex b);
t_complex		c_set(long double re, long double im);
t_complex		c_pow(t_complex a, int n);

#endif
