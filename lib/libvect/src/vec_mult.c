/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 08:19:32 by scollon           #+#    #+#             */
/*   Updated: 2016/01/21 08:26:24 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

t_vect	vec_mult(const t_vect v, const float mult)
{
	t_vect	r;

	r.x = v.x * mult;
	r.y = v.y * mult;
	return (r);
}
