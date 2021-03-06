/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_magnitude.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:46:14 by scollon           #+#    #+#             */
/*   Updated: 2016/02/09 16:29:57 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

double	vec3_magnitude(t_vect3d v3)
{
	return (sqrt((v3.x * v3.x) + (v3.y * v3.y) + (v3.z * v3.z)));
}
