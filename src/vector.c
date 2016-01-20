/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:07:32 by scollon           #+#    #+#             */
/*   Updated: 2016/01/20 16:02:05 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		vec_cmp(const t_vect va, const t_vect vb)
{
	if (fabs(va.x - vb.x) > 0.897)
		return (0);
	if (fabs(va.y - vb.y) > 0.897)
		return (0);
	return (1);
}

t_vectI	vec_to_int(const t_vect v)
{
	t_vectI	r;

	r.x = (int)v.x;
	r.y = (int)v.y;
	return (r);
}

t_vect	int_to_vec(const t_vectI i)
{
	t_vect	r;

	r.x = (float)i.x;
	r.y = (float)i.y;
	return (r);
}

float	vec_magnitude(const t_vect v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

t_vect	vec_create(float x, float y)
{
	t_vect	r;

	r.x = x;
	r.y = y;
	return (r);
}

void    vec_rotate(t_vect *v, float theta)
{
	t_vect  t;

	theta *= D2R;
	t.x = v->x * cos(theta) + v->y * -sin(theta);
	t.y = v->x * sin(theta) + v->y * cos(theta);
	v->x = t.x;
	v->y = t.y;
}
