/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_fill2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 15:53:18 by lminta            #+#    #+#             */
/*   Updated: 2019/06/25 20:40:55 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol_mlx.h"

t_mlx	g_mlx(t_mlx *mlx, int flag)
{
	static t_mlx	gmlx;

	if (flag)
	{
		gmlx = *mlx;
		return (gmlx);
	}
	else
		return (gmlx);
}

t_xy	g_win(t_xy *win, int flag)
{
	static t_xy	gwin;

	if (flag)
	{
		gwin = *win;
		return (gwin);
	}
	else
		return (gwin);
}

t_color	g_end_c(t_color color, int flag)
{
	static t_color	gcolor;

	if (flag)
	{
		gcolor = color;
		return (gcolor);
	}
	else
		return (gcolor);
}
