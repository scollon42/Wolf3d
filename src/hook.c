/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 07:27:23 by scollon           #+#    #+#             */
/*   Updated: 2016/01/20 14:11:53 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		move(t_env *e)
{
	if(e->key.ku || e->key.kd || e->key.kl || e->key.kr)
	{
		if (e->key.ku)
			e->cam.pos = vec_add(e->cam.pos, vec_scale(e->cam.dir, 5));
		if (e->key.kd)
			e->cam.pos = vec_sub(e->cam.pos, vec_scale(e->cam.dir, 5));
		if (e->key.kl)
		{
			vec_rotate(&e->cam.dir, -2.5);
			vec_rotate(&e->cam.plan, -2.5);
		}
		if (e->key.kr)
		{
			vec_rotate(&e->cam.dir, 2.5);
			vec_rotate(&e->cam.plan, 2.5);
		}
		expose_hook(e);
	}
	return (1);
}

void	draw_scene(t_env *e)
{
	t_vect	dir;
	t_vect	plan;
	t_vect	plan2;

	dir = vec_add(e->cam.pos, e->cam.dir);
	plan = vec_add(dir, e->cam.plan);
	plan2 = vec_sub(dir, e->cam.plan);
	draw_line(e, vec_to_int(e->cam.pos), vec_to_int(dir), 0x00FFFF);
	draw_line(e, vec_to_int(plan), vec_to_int(plan2), 0xFFFFFF);
	raycast(e);
}

int		expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img.adr);
	init_img(e);
	draw_scene(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.adr, 0, 0);
	return (1);
}
