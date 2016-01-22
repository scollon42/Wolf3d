/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 07:29:01 by scollon           #+#    #+#             */
/*   Updated: 2016/01/22 15:48:37 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

static int	expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win.adr);
	mlx_destroy_image(e->mlx, e->img.adr);
	img_init(e);
	render(e);
	mlx_put_image_to_window(e->mlx, e->win.adr, e->img.adr, 0, 0);
	put_sprites(e);
	return (0);
}

static int	move(t_env *e)
{
	if (e->key.kup == 1)
		e->cam.pos = vec_add(e->cam.pos, vec_scale(e->cam.dir, e->cam.run));
	if (e->key.kdn == 1)
		e->cam.pos = vec_sub(e->cam.pos, vec_scale(e->cam.dir, e->cam.run));
	if (e->key.klt == 1)
	{
		vec_rotate(&e->cam.dir, -2.5);
		vec_rotate(&e->cam.pln, -2.5);
	}
	if (e->key.krt == 1)
	{
		vec_rotate(&e->cam.dir, 2.5);
		vec_rotate(&e->cam.pln, 2.5);
	}
	e->cam.run = e->key.run == 1 ? 0.05 : 0.02;
	expose_hook(e);
	return (0);
}

void		core(t_env *e)
{
	mlx_expose_hook(e->win.adr, expose_hook, e);
	mlx_loop_hook(e->mlx, move, e);
	mlx_hook(e->win.adr, 6, (1L << 6), mouse_pos, e);
	mlx_hook(e->win.adr, 2, (1L << 0), key_press, e);
	mlx_hook(e->win.adr, 3, (1L << 1), key_release, e);
	mlx_loop(e->mlx);
}
