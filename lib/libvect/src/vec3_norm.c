/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:53:37 by scollon           #+#    #+#             */
/*   Updated: 2016/02/08 13:18:33 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

t_vect3d	vec3_norm(t_vect3d v3)
{
	float		magnitude;
	t_vect3d	r;

	magnitude = vec3_magnitude(v3);
	r.x = v3.x / magnitude;
	r.y = v3.y / magnitude;
	r.z = v3.z / magnitude;
	return (r);
}
