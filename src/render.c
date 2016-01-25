/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 07:38:09 by scollon           #+#    #+#             */
/*   Updated: 2016/01/23 09:28:40 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

void		render(t_env *e)
{
	int	x;

	x = 0;
	while (++x <= e->win.w)
	{
		raycast_init(e, x);
		raycast_calc(e);
		raycast_cast(e);
		raycast_dist(e);
		raycast_draw(e, x);
	}
}
