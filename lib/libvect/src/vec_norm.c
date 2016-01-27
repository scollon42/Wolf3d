/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 08:19:54 by scollon           #+#    #+#             */
/*   Updated: 2016/01/27 15:56:21 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

t_vect	vec_norm(const t_vect v)
{
	t_vect	r;
	float	mag;

	mag = vec_magnitude(v);
	r.x = v.x / mag;
	r.y = v.y / mag;
	return (r);
}
