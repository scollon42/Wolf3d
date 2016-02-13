/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:32:49 by scollon           #+#    #+#             */
/*   Updated: 2016/02/08 13:17:00 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

t_vect3d	vec3_add(const t_vect3d v3a, const t_vect3d v3b)
{
	t_vect3d	r;

	r.x = v3a.x + v3b.x;
	r.y = v3a.y + v3b.y;
	r.z = v3a.z + v3b.z;
	return (r);
}
