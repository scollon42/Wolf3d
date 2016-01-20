/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 07:31:26 by scollon           #+#    #+#             */
/*   Updated: 2016/01/20 10:15:17 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	img_pixel_put(t_env *e, int x, int y, int color)
{
	int		pos;

	if (x >= 0 && x < e->ws.x && y >= 0 && y < e->ws.y)
	{
		pos = (x * e->img.bpp / 8) + (y * e->img.sl);
		e->img.img[pos] = color % 256;
		e->img.img[pos + 1] = (color >> 8) % 256;
		e->img.img[pos + 2] = (color >> 16) % 256;
	}
}

void    draw_line(t_env *e, t_vectI src, t_vectI dst, int color)
{
	int	   	err;
	int		e2;
	t_vectI d;
	t_vectI	s;

	d.x = abs((dst.x - src.x));
	d.y = -abs((dst.y - src.y));
	s.x = (src.x < dst.x ? 1 : -1);
	s.y = (src.y < dst.y ? 1 : -1);
	err = d.x + d.y;
	while (src.x != dst.x || src.y != dst.y)
	{
		img_pixel_put(e, src.x, src.y, color);
		e2 = 2 * err;
		err = (e2 >= d.y ? err + d.y : err);
		src.x = (e2 >= d.y ? src.x + s.x : src.x);
		err = (e2 <= d.x ? err + d.x : err);
		src.y = (e2 <= d.x ? src.y + s.y : src.y);
	}
}
