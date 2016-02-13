/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:28:53 by scollon           #+#    #+#             */
/*   Updated: 2016/02/09 16:29:12 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

t_vect3d	vec3_create(const double x, const double y, const double z)
{
	t_vect3d	r;

	r = (t_vect3d) {x, y, z};
	return (r);
}
