/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 07:48:40 by scollon           #+#    #+#             */
/*   Updated: 2016/01/25 09:53:36 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

int		rgb_to_hex(int r, int g, int b)
{
	int color;

	color = b;
	color += g * 256;
	color += (r * 256) * 256;
	return (color);
}

void	img_pixel_put(t_env *e, int x, int y, int color)
{
	int	pos;

	if (x >= 0 && x < e->win.w && y >= 0 && y < e->win.h)
	{
		pos = (x * e->img.bpp / 8) + (y * e->img.sl);
		e->img.img[pos] = color % 256;
		e->img.img[pos + 1] = (color >> 8) % 256;
		e->img.img[pos + 2] = (color >> 16) % 256;
	}
}
