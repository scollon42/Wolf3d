/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:43:46 by scollon           #+#    #+#             */
/*   Updated: 2016/02/09 16:29:41 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

t_vect3d	vec3_div(const t_vect3d v3a, const double div)
{
	t_vect3d	r;

	if (div == 0)
		return ((t_vect3d)v3a);
	r.x = v3a.x / div;
	r.y = v3a.y / div;
	r.z = v3a.z / div;
	return (r);
}
