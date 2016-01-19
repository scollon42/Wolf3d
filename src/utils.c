/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 07:31:26 by scollon           #+#    #+#             */
/*   Updated: 2016/01/19 14:45:34 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    draw_line(t_env *e, t_rect src, t_rect dst)
{
	int     err;
	int     e2;
	t_rect 	d;
	t_rect	s;

	d.x = fabs((dst.x - src.x));
	d.y = -fabs((dst.y - src.y));
	s.x = (src.x < dst.x ? 1 : -1);
	s.y = (src.y < dst.y ? 1 : -1);
	err = d.x + d.y;
	while (src.x != dst.x || src.y != dst.y)
	{
		mlx_pixel_put(e->mlx, e->win, src.x, src.y, 0xFFFFFF);
		e2 = 2 * err;
		err = (e2 >= d.y ? err + d.y : err);
		src.x = (e2 >= d.y ? src.x + s.x : src.x);
		err = (e2 <= d.x ? err + d.x : err);
		src.y = (e2 <= d.x ? src.y + s.y : src.y);
	}
}

t_rect	add_vector(const t_rect vdst, const t_rect vsrc)
{
	t_rect	r;
	r.x = vdst.x + vsrc.x;
	r.y = vdst.y + vsrc.y;
	return (r);
}

void	rotate_vector(t_rect *v, float theta)
{
	t_rect	t;

	t.x = v->x * cos(theta) + v->y * -sin(theta);
	t.y = v->x * sin(theta) + v->y * cos(theta);
	v->x = t.x;
	v->y = t.y;
}
