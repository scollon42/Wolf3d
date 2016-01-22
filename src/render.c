/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 07:38:09 by scollon           #+#    #+#             */
/*   Updated: 2016/01/22 17:08:44 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

int			rgb_to_hex(int r, int g, int b)
{
	int color;

	color = b;
	color += g * 256;
	color += (r * 256) * 256;
	return (color);
}

void		img_pixel_put(t_env *e, int x, int y, int color)
{
	int		pos;

	if (x >= 0 && x < e->win.w && y >= 0 && y < e->win.h)
	{
		pos = (x * e->img.bpp / 8) + (y * e->img.sl);
		e->img.img[pos] = color % 256;
		e->img.img[pos + 1] = (color >> 8) % 256;
		e->img.img[pos + 2] = (color >> 16) % 256;
	}
}

static void raycast_init(t_env *e, int x)
{
	t_vect	pow;

	e->ray.cam = (2 * x / (float)e->win.w) - 1;
	e->ray.pos = e->cam.pos;
	e->ray.dir.x = e->cam.dir.x + e->cam.pln.x * e->ray.cam;
	e->ray.dir.y = e->cam.dir.y + e->cam.pln.y * e->ray.cam;
	e->ray.map = vec_to_int(e->ray.pos);
	pow.x = e->ray.dir.x * e->ray.dir.x;
	pow.y = e->ray.dir.y * e->ray.dir.y;
	e->ray.a.x = sqrt(1 + pow.y / pow.x);
	e->ray.a.y = sqrt(1 + pow.x / pow.y);
	e->ray.hit = 0;
}

static void	raycast_calc(t_env *e)
{
	if (e->ray.dir.x < 0)
	{
		e->ray.step.x = -1;
		e->ray.len.x = (e->ray.pos.x - e->ray.map.x) * e->ray.a.x;
	}
	else
	{
		e->ray.step.x = 1;
		e->ray.len.x = (e->ray.map.x + 1.0 - e->ray.pos.x) * e->ray.a.x;
	}
	if (e->ray.dir.y < 0)
	{
		e->ray.step.y = -1;
		e->ray.len.y = (e->ray.pos.y - e->ray.map.y) * e->ray.a.y;
	}
	else
	{
		e->ray.step.y = 1;
		e->ray.len.y = (e->ray.map.y + 1.0 - e->ray.pos.y) * e->ray.a.y;
	}
}

static void	raycast_cast(t_env *e)
{
	while (e->ray.hit == 0)
	{
		if (e->ray.len.x < e->ray.len.y)
		{
			e->ray.len.x += e->ray.a.x;
			e->ray.map.x += e->ray.step.x;
			e->ray.side = 0;
		}
		else
		{
			e->ray.len.y += e->ray.a.y;
			e->ray.map.y += e->ray.step.y;
			e->ray.side = 1;
		}
		if (e->ray.map.x > e->map.size - 1 || e->ray.map.y > e->map.size - 1 ||
			e->ray.map.x < 0 || e->ray.map.y < 0)
			break ;
		if (e->map.map[e->ray.map.y][e->ray.map.x] > 0)
			e->ray.hit = 1;
	}
	if (e->ray.side == 0)
		e->ray.dist = fabs((e->ray.map.x - e->ray.pos.x +
		(1 - e->ray.step.x) / 2) / e->ray.dir.x);
	else
		e->ray.dist = fabs((e->ray.map.y - e->ray.pos.y +
		(1 - e->ray.step.y) / 2) / e->ray.dir.y);
}

void		render(t_env *e)
{
	int		hl;
	int		ds;
	int		de;
	t_vectI	r;

	r = vec_to_int(vec_create(-1, 0));
	while (++r.x <= e->win.w)
	{
		raycast_init(e, r.x);
		raycast_calc(e);
		raycast_cast(e);
		hl = abs((int)(e->win.h / e->ray.dist));
		ds = (int)(-hl / 2 + e->win.h / 2);
		de = (int)(hl / 2 + e->win.h / 2);
		if (ds < 0)
			ds = 0;
		if (de >= e->win.h)
			de = e->win.h - 1;
		r.y = ds;
		while (r.y < de)
		{
			if (e->ray.side == 1)
				img_pixel_put(e, r.x, r.y, 0xFFFFFF);
			else
				img_pixel_put(e, r.x, r.y, 0xcccccc);
			r.y++;
		}
		if (de < 0)
			de = e->win.h;
		r.y = de;
		while (r.y < e->win.h)
		{
			img_pixel_put(e, r.x, r.y, 0x7B7263);
			img_pixel_put(e, r.x, e->win.h - r.y - 1, 0x101010);
			r.y++;
		}
	}
}
