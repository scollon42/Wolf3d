/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:58:18 by scollon           #+#    #+#             */
/*   Updated: 2016/02/09 16:30:58 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

t_vect3d	vec3_scale(t_vect3d v3, double scale)
{
	t_vect3d	r;

	r = vec3_norm(v3);
	r.x *= scale;
	r.y *= scale;
	r.z *= scale;
	return (r);
}
