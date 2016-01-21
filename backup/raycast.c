/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 13:14:23 by scollon           #+#    #+#             */
/*   Updated: 2016/01/21 13:53:04 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	raycast(t_env *e)
{
	t_vect	ray;
	t_vect	ray_pos;
	t_vect	ray_dir;
	t_vect	ray_len;
	t_vect	a;
	t_vectI	step;
	t_vectI	map;
	int		hit;
	int		x;
	int		y;
	int		side;
	int		dist;

	x = 0;
	y = 0;
	while (x <= e->ws.x)
	{
		hit = 0;
		ray_pos = e->cam.pos;
		map.x = e->cam.pos.x;
		map.y = e->cam.pos.y;
		ray_dir.x = e->cam.dir.x + e->cam.plan.x * ((2 * x / e->ws.x) - 1);
		ray_dir.y = e->cam.dir.y + e->cam.plan.y * ((2 * x / e->ws.x) - 1);
		a.x = sqrt(1 + (pow(e->cam.dir.y, 2) / pow(e->cam.dir.x, 2)));
		a.y = sqrt(1 + (pow(e->cam.dir.x, 2) / pow(e->cam.dir.y, 2)));
		if (ray_dir.x < 0)
		{
			step.x = -1;
			ray_len.x = (ray_pos.x - map.x) * a.x;
		}
		else
		{
			step.x = 1;
			ray_len.x = (map.x + 1.0 - ray_pos.x) * a.x;
		}
		if (e->cam.dir.y < 0)
		{
			step.y = -1;
			ray_len.y = (ray_pos.y - map.y) * a.y;
		}
		else
		{
			step.y = 1;
			ray_len.y = (map.y + 1.0 - ray_pos.y) * a.y;
		}
		while (!hit)
		{
			if (ray_len.x < ray_len.y)
			{
				ray_len.x += a.x;
				map.x += step.x;
				side = 0;
			}
			else
			{
				ray_len.y += a.y;
				map.y += step.y;
				side = 1;
			}
			if (e->map.map[(int)map.x][(int)map.y] > 0)
				hit = 1;
		}
		if (!side)
			dist = abs((int)((map.x - ray_pos.x + (1 - step.x) / 2) / ray_dir.x));
		else
			dist = abs((int)((map.y - ray_pos.y + (1 - step.y) / 2) / ray_dir.y));
		int	h_line = abs((int)(e->ws.y / dist));
		int	ds	= (-h_line / 2 + e->ws.y / 2);
		int	de	= (h_line / 2 + e->ws.y / 2);
		if (!ds)
			ds = 0;
		if (de >= e->ws.y)
			de = e->ws.y - 1;
		y = ds;
		while (y < de)
		{
			int color = 0xf2f2f2;
			if (side == 1)
				color = 0xcccccc;
			img_pixel_put(e, x, y, color);
			y++;
		}
		x++;
	}
}
