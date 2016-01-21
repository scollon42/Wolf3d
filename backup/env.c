/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 07:27:38 by scollon           #+#    #+#             */
/*   Updated: 2016/01/21 15:50:53 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_img(t_env *e)
{
	if (!(e->img.adr = mlx_new_image(e->mlx, e->ws.x, e->ws.y)))
		exit(0);
	e->img.img = mlx_get_data_addr(e->img.adr,
			&e->img.bpp, &e->img.sl, &e->img.endian);
}

static void	init_cam(t_env *e)
{
	e->cam.pos.x = 24;
	e->cam.pos.y = 24;
	e->cam.dir.x = -1;
	e->cam.dir.y = 0;
	e->cam.plan.x = 0;
	e->cam.plan.y = 1;
	e->cam.h = e->map.wall_h / 2;
}

t_env		*init_env(void)
{
	t_env *e;

	if(!(e = (t_env *)malloc(sizeof(t_env))))
		exit(0);
	if(!(e->mlx = mlx_init()))
		exit(0);
	e->ws.x = 840;
	e->ws.y = 480;
	e->win = mlx_new_window(e->mlx, e->ws.x, e->ws.y, "WOLF3D @ 42");
	e->mse.x = e->cam.dir.x;
	e->mse.y = e->cam.dir.y;
	init_img(e);
	init_map(e);
	init_cam(e);
	return (e);
}
