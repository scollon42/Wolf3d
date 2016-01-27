/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 08:17:02 by scollon           #+#    #+#             */
/*   Updated: 2016/01/27 15:55:03 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

int		vec_cmp(const t_vect va, const t_vect vb)
{
	if (fabs(va.x - vb.x) > 0.897)
		return (0);
	if (fabs(va.y - vb.y) > 0.897)
		return (0);
	return (1);
}
