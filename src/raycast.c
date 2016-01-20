/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 13:14:23 by scollon           #+#    #+#             */
/*   Updated: 2016/01/20 16:48:32 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	raycast(t_env *e)
{
	int		i;
	int		j;
	int		hit;
	t_vect	ray;
	t_vect	ray_t;
	t_vectI	pos;

	i = 0;
	ray = vec_sub(e->cam.dir, e->cam.plan);
	pos.x = (int)(e->cam.pos.x * 1.0 / (float)e->ws.x * e->map.size);
	pos.y = (int)(e->cam.pos.y * 1.0 / (float)e->ws.y * e->map.size);
	ray = vec_norm(ray);
	while (++i <= e->cam.view * 2)
	{
		vec_rotate(&ray, e->cam.r_ang);
		hit = 0;
		j = 1;
		ray_t = ray;
		while (!hit)
		{
			if (pos.x + ray_t.x > e->map.size - 1 ||
				pos.y + ray_t.y > e->map.size - 1 ||
				pos.x + ray_t.x < 0 || pos.y + ray_t.y < 0)
				break;
			if (e->map.map[pos.y + (int)ray_t.y][pos.x + (int)ray_t.x] > 0)
				hit = 1;
			ray_t = vec_scale(ray_t, j);
			j++;
		}
	}
}
