/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:35:38 by scollon           #+#    #+#             */
/*   Updated: 2016/02/09 16:30:37 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

void	vec3_rotate(t_vect3d *v, double theta, int axis)
{
	t_vect3d	t;

	theta *= D2R;
	t = vec3_create(v->x, v->y, v->z);
	if (axis == Z)
	{
		t.x = v->x * cos(theta) + v->y * -sin(theta);
		t.y = v->x * sin(theta) + v->y * cos(theta);
	}
	if (axis == Y)
	{
		t.x = v->x * cos(theta) + v->z * sin(theta);
		t.z = v->x * -sin(theta) + v->z * cos(theta);
	}
	if (axis == X)
	{
		t.y = v->x * cos(theta) + v->z * -sin(theta);
		t.z = v->y * sin(theta) + v->z * cos(theta);
	}
	v->x = t.x;
	v->y = t.y;
	v->z = t.z;
}
