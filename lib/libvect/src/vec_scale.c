/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 08:19:44 by scollon           #+#    #+#             */
/*   Updated: 2016/01/27 15:58:45 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

t_vect	vec_scale(const t_vect v, const float scale)
{
	t_vect	r;

	r = vec_norm(v);
	r.x *= scale;
	r.y *= scale;
	return (r);
}
