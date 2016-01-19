/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 07:27:23 by scollon           #+#    #+#             */
/*   Updated: 2016/01/19 17:16:41 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		move(t_env *e)
{
	if(e->key.ku || e->key.kd || e->key.kl || e->key.kr)
	{
		if (e->key.ku)
			e->cam.pos = add_vector(e->cam.pos, scale_vector(e->cam.dir, 5));
		if (e->key.kd)
			e->cam.pos = sub_vector(e->cam.pos, scale_vector(e->cam.dir, 5));
		if (e->key.kl)
		{
			rotate_vector(&e->cam.dir, -0.05);
			rotate_vector(&e->cam.plan, -0.05);
		}
		if (e->key.kr)
		{
			rotate_vector(&e->cam.dir, 0.05);
			rotate_vector(&e->cam.plan, 0.05);
		}
		expose_hook(e);
	}
	return (1);
}

void	draw_scene(t_env *e)
{
	t_rect	dir;
	t_rect	plan;
	t_rect	plan2;

	dir = add_vector(e->cam.pos, e->cam.dir);
	plan = add_vector(dir, e->cam.plan);
	plan2 = sub_vector(dir, e->cam.plan);
	draw_line(e, int_vector(e->cam.pos), int_vector(dir), 0x00FFFF);
	draw_line(e, int_vector(plan), int_vector(plan2), 0xFFFFFF);
	draw_line(e, int_vector(plan), int_vector(plan2), 0xFFFFFF);
	draw_line(e, int_vector(e->cam.pos), int_vector(plan2), 0xFF0000);
	draw_line(e, int_vector(e->cam.pos), int_vector(plan), 0xFF0000);
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
