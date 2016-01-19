/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 07:27:38 by scollon           #+#    #+#             */
/*   Updated: 2016/01/19 14:21:06 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_env	*init_env(void)
{
	t_env *e;

	if(!(e = (t_env *)malloc(sizeof(t_env))))
		exit(0);
	if(!(e->mlx = mlx_init()))
		exit(0);
	e->ws.x = 800;
	e->ws.y = 800;
	e->win = mlx_new_window(e->mlx, e->ws.x, e->ws.y, "WOLF3D @ 42");
	e->cam.pos.x = e->ws.x / 2;
	e->cam.pos.y = e->ws.y / 2;
	e->cam.dir.x = 0;
	e->cam.dir.y = -277;
	e->cam.plan.x = 200;
	e->cam.plan.y = 0;
	e->mse.x = e->cam.dir.x;
	e->mse.y = e->cam.dir.y;
	return (e);
}
