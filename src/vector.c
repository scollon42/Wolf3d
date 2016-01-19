/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:07:32 by scollon           #+#    #+#             */
/*   Updated: 2016/01/19 16:40:21 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_rect  add_vector(const t_rect vdst, const t_rect vsrc)
{
	t_rect  r;

	r.x = vdst.x + vsrc.x;
	r.y = vdst.y + vsrc.y;
	return (r);
}

t_rect	sub_vector(const t_rect vdst, const t_rect vsrc)
{
	t_rect  r;

	r.x = vdst.x - vsrc.x;
	r.y = vdst.y - vsrc.y;
	return (r);
}

t_rect	scale_vector(const t_rect vdst, const float scale)
{
	t_rect	r;

	r = norm_vector(vdst);
	r.x *= scale;
	r.y *= scale;
	return (r);
}

t_rect	norm_vector(const t_rect vector)
{
	t_rect	r;
	float	mag;

	mag = mag_vector(vector);
	r.x = vector.x / mag;
	r.y = vector.y / mag;
	return (r);
}

t_point	int_vector(const t_rect vector)
{
	t_point	r;

	r.x = (int)vector.x;
	r.y = (int)vector.y;
	return (r);
}

float	mag_vector(const t_rect vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y));
}

void    rotate_vector(t_rect *v, float theta)
{
	t_rect  t;

	t.x = v->x * cos(theta) + v->y * -sin(theta);
	t.y = v->x * sin(theta) + v->y * cos(theta);
	v->x = t.x;
	v->y = t.y;
}
