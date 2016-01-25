/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:20:20 by scollon           #+#    #+#             */
/*   Updated: 2016/01/25 16:57:32 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

void	raycast_tx(t_env *e, int ds, int de, int hl)
{
	int 		i;
	int			pos;
	double		wall;

	i = ds - 1;
	e->texv.index = e->map.map[(int)e->ray.map.y][(int)e->ray.map.x] - 1;
	e->texv.index < 0 || e->texv.index >= e->t_nb ? e->texv.index = 0 : 0;
	wall = e->ray.side == 1 ? e->ray.pos.x + ((e->ray.map.y - e->ray.pos.y +
			(1 - e->ray.step.y) / 2) / e->ray.dir.y) * e->ray.dir.x :
			e->ray.pos.y + ((e->ray.map.x - e->ray.pos.x +
	(1 - e->ray.step.x) / 2) / e->ray.dir.x) * e->ray.dir.y;
	wall -= floor(wall);
	e->texv.tex.x = (int)(wall * e->tex[e->texv.index].w);
	while (++i < de)
	{
		e->texv.tex.y = (i * 2 - e->win.h + hl) *
						(e->tex[e->texv.index].h / 2) / hl;
		pos = (e->texv.tex.x * e->tex[e->texv.index].bpp / 8)
			+ (e->texv.tex.y * e->tex[e->texv.index].sl);
		e->texv.color = e->tex[e->texv.index].spr[pos];
		e->texv.color += e->tex[e->texv.index].spr[pos + 1] * 256;
		e->texv.color += (e->tex[e->texv.index].spr[pos + 2] * 256) * 256;
		!e->ray.side ? e->texv.color = (e->texv.color >> 1) & 0x7f7f7f : 0;
		img_pixel_put(e, e->ray.x, i, e->texv.color);
	}
}
