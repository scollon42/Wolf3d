/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 07:38:09 by scollon           #+#    #+#             */
/*   Updated: 2016/01/25 15:32:18 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

void		render(t_env *e)
{
	e->ray.x = 0;
	while (++e->ray.x <= e->win.w)
	{
		raycast_init(e, e->ray.x);
		raycast_calc(e);
		raycast_cast(e);
		raycast_dist(e);
		raycast_draw(e, e->ray.x);
	}
}
