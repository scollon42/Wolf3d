/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:20:20 by scollon           #+#    #+#             */
/*   Updated: 2016/01/26 15:36:58 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

void	raycast_tx(t_env *e, int ds, int de, int hl)
{
	int	y;
	int	pos;

	y = ds - 1;
	e->tex.index = e->map.map[(int)e->ray.map.y][(int)e->ray.map.x] - 1;
	e->tex.index < 0 || e->tex.index >= e->t_nb ? e->tex.index = 0 : 0;
	e->tex.wall = e->ray.side == 1 ? e->ray.pos.x + ((e->ray.map.y -
				e->ray.pos.y + (1 - e->ray.step.y) / 2) / e->ray.dir.y)
				* e->ray.dir.x : e->ray.pos.y + ((e->ray.map.x - e->ray.pos.x +
				(1 - e->ray.step.x) / 2) / e->ray.dir.x) * e->ray.dir.y;
	e->tex.wall -= floor(e->tex.wall);
	e->tex.tex.x = (int)(e->tex.wall * e->tex.img[e->tex.index].w);
	while (++y < de)
	{
		e->tex.tex.y = (y * 2 - e->win.h + hl) *
						(e->tex.img[e->tex.index].h / 2) / hl;
		pos = (e->tex.tex.x * e->tex.img[e->tex.index].bpp / 8)
			+ (e->tex.tex.y * e->tex.img[e->tex.index].sl);
		e->tex.color = e->tex.img[e->tex.index].spr[pos];
		e->tex.color += e->tex.img[e->tex.index].spr[pos + 1] * 256;
		e->tex.color += (e->tex.img[e->tex.index].spr[pos + 2] * 256) * 256;
		!e->ray.side ? e->tex.color = (e->tex.color >> 1) & 0x7f7f7f : 0;
		img_pixel_put(e, e->ray.x, y, e->tex.color);
	}
}
