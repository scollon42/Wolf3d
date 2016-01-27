/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:20:20 by scollon           #+#    #+#             */
/*   Updated: 2016/01/27 15:21:57 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

static void	floor_draw(t_env *e, int de)
{
	int		y;
	int		pos;

	y = de;
	while (++y < e->win.h)
	{
		e->flo.dist = e->win.h / (2.0 * y - e->win.h);
		e->flo.wei = e->flo.dist / e->ray.dist;
		e->flo.cur.x = e->flo.wei * e->flo.wall.x +
			(1.0 - e->flo.wei) * e->cam.pos.x;
		e->flo.cur.y = e->flo.wei * e->flo.wall.y +
			(1.0 - e->flo.wei) * e->cam.pos.y;
		e->flo.tex.x = (int)(e->flo.cur.x * e->flo.img.w) % e->flo.img.w;
		e->flo.tex.y = (int)(e->flo.cur.y * e->flo.img.h) % e->flo.img.h;
		pos = (e->flo.tex.x * e->flo.img.opp) + (e->flo.tex.y * e->flo.img.sl);
		e->flo.color = e->flo.img.spr[pos];
		e->flo.color += e->flo.img.spr[pos + 1] * 256;
		e->flo.color += (e->flo.img.spr[pos + 2] * 256) * 256;
		img_pixel_put(e, e->ray.x, y, e->flo.color);
	}
}

static void	tex_floor(t_env *e, int de)
{
	if (e->ray.side == 0)
	{
		e->ray.dir.x > 0 ? e->flo.wall.x = e->ray.map.x : 0;
		e->ray.dir.x < 0 ? e->flo.wall.x = e->ray.map.x + 1.0 : 0;
		e->flo.wall.y = e->ray.map.y + e->tex.wall;
	}
	else if (e->ray.side == 1)
	{
		e->flo.wall.x = e->ray.map.x + e->tex.wall;
		e->ray.dir.y > 0 ? e->flo.wall.y = e->ray.map.y : 0;
		e->ray.dir.y < 0 ? e->flo.wall.y = e->ray.map.y + 1.0 : 0;
	}
	floor_draw(e, de);
}

void		raycast_tx(t_env *e, int ds, int de, int hl)
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
			(e->tex.img[e->tex.index].h2) / hl;
		pos = (e->tex.tex.x * e->tex.img[e->tex.index].opp)
			+ (e->tex.tex.y * e->tex.img[e->tex.index].sl);
		e->tex.color = e->tex.img[e->tex.index].spr[pos];
		e->tex.color += e->tex.img[e->tex.index].spr[pos + 1] * 256;
		e->tex.color += (e->tex.img[e->tex.index].spr[pos + 2] * 256) * 256;
		!e->ray.side ? e->tex.color = (e->tex.color >> 1) & 0x7f7f7f : 0;
		img_pixel_put(e, e->ray.x, y, e->tex.color);
	}
	tex_floor(e, de);
}
