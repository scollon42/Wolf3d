/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 07:27:38 by scollon           #+#    #+#             */
/*   Updated: 2016/01/19 17:13:07 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_img(t_env *e)
{
	if (!(e->img.adr = mlx_new_image(e->mlx, e->ws.x, e->ws.y)))
		exit(0);
	e->img.img = mlx_get_data_addr(e->img.adr,
			&e->img.bpp, &e->img.sl, &e->img.endian);
}

t_env	*init_env(void)
{
	t_env *e;

	if(!(e = (t_env *)malloc(sizeof(t_env))))
		exit(0);
	if(!(e->mlx = mlx_init()))
		exit(0);
	e->ws.x = 1200;
	e->ws.y = 1200;
	e->win = mlx_new_window(e->mlx, e->ws.x, e->ws.y, "WOLF3D @ 42");
	e->cam.pos.x = e->ws.x / 2;
	e->cam.pos.y = e->ws.y / 2;
	e->cam.dir.x = 0;
	e->cam.dir.y = -277;
	e->cam.plan.x = 160;
	e->cam.plan.y = 0;
	e->mse.x = e->cam.dir.x;
	e->mse.y = e->cam.dir.y;
	init_img(e);
	return (e);
}
