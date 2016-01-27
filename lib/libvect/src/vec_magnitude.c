/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_magnitude.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 08:18:05 by scollon           #+#    #+#             */
/*   Updated: 2016/01/27 15:55:38 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

float	vec_magnitude(const t_vect v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}
