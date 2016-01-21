/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 08:18:58 by scollon           #+#    #+#             */
/*   Updated: 2016/01/21 08:19:11 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

t_vect  vec_add(const t_vect va, const t_vect vb)
{
	t_vect  r;

	r.x = va.x + vb.x;
	r.y = va.y + vb.y;
	return (r);
}