/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 07:38:09 by scollon           #+#    #+#             */
/*   Updated: 2016/01/28 08:25:24 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

void		skybox_draw(t_env *e)
{
	int		x;
	int		y;
	int		xt;
	int		pos;
	int		color;

	y = -1;
	e->skb.pos.x > e->skb.w ? e->skb.pos.x = 0 : 0;
	xt = e->skb.pos.x;
	while (++y < e->win.h2)
	{
		x = -1;
		e->skb.pos.x = xt;
		while (++x < e->skb.w)
		{
			pos = (e->skb.pos.x * e->skb.opp) + (y * e->skb.sl);
			color = e->skb.skb[pos];
			color += e->skb.skb[pos + 1] * 256;
			color += (e->skb.skb[pos + 2] * 256) * 256;
			img_pixel_put(e, x, y, color);
			e->skb.pos.x + 1 > e->skb.w ? e->skb.pos.x = 1 : e->skb.pos.x++;
		}
	}
}

void		render(t_env *e)
{
	e->ray.x = -1;
	while (++e->ray.x <= e->win.w)
	{
		raycast_init(e, e->ray.x);
		raycast_calc(e);
		raycast_cast(e);
		raycast_dist(e);
		raycast_draw(e, e->ray.x);
	}
}
