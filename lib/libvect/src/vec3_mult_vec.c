/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mult_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:10:50 by scollon           #+#    #+#             */
/*   Updated: 2016/02/08 13:17:35 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

t_vect3d	vec3_mult_vec(const t_vect3d v3a, t_vect3d v3b)
{
	t_vect3d	r;

	r.x = v3a.x * v3b.x;
	r.y = v3a.y * v3b.y;
	r.z = v3a.z * v3b.z;
	return (r);
}
