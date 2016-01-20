/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 07:32:50 by scollon           #+#    #+#             */
/*   Updated: 2016/01/20 07:54:14 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vect  vec_add(const t_vect va, const t_vect vb)
{
	t_vect  r;

	r.x = va.x + vb.x;
	r.y = va.y + vb.y;
	return (r);
}

t_vect	vec_sub(const t_vect va, const t_vect vb)
{
	t_vect  r;

	r.x = va.x - vb.x;
	r.y = va.y - vb.y;
	return (r);
}
t_vect	vec_mult(const t_vect v, const float mult)
{
	t_vect	r;

	r.x = v.x * mult;
	r.y = v.y * mult;
	return (r);
}
t_vect	vec_scale(const t_vect v, const float scale)
{
	t_vect	r;

	r = vec_norm(v);
	r.x *= scale;
	r.y *= scale;
	return (r);
}

t_vect	vec_norm(const t_vect v)
{
	t_vect	r;
	float	mag;

	mag = vec_magnitude(v);
	r.x = v.x / mag;
	r.y = v.y / mag;
	return (r);
}
