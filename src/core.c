/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 07:29:01 by scollon           #+#    #+#             */
/*   Updated: 2016/01/23 12:46:26 by scollon          ###   ########.fr       */
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
	float	rot;
	t_vect	tmp;

	tmp = e->cam.pos;
	if (e->key.w == 1)
		tmp = vec_add(e->cam.pos, vec_scale(e->cam.dir, e->cam.run));
	if (e->key.s == 1)
		tmp = vec_sub(e->cam.pos, vec_scale(e->cam.dir, e->cam.run));
	if (e->key.e)
		tmp = vec_add(e->cam.pos, vec_scale(e->cam.pln, e->cam.run));
	if (e->key.q)
		tmp = vec_sub(e->cam.pos, vec_scale(e->cam.pln, e->cam.run));
	e->key.a ? rot = -2.5 : 0;
	e->key.d ? rot = 2.5 : 0;
	vec_rotate(&e->cam.dir, rot);
	vec_rotate(&e->cam.pln, rot);
	e->cam.pos = e->map.map[(int)tmp.y][(int)tmp.x] == 0 ? tmp : e->cam.pos;
	e->cam.shoot > 0 ? e->cam.shoot++ : 0;
	e->cam.run = e->key.run == 1 ? 0.05 : 0.02;
	expose_hook(e);
	return (0);
}

int			mouse_event(int btn, int x, int y, t_env *e)
{
	if (btn == 1)
		e->cam.shoot = 1;
	e->mse.x = x;
	e->mse.y = y;
	return (1);
}

void		core(t_env *e)
{
	mlx_expose_hook(e->win.adr, expose_hook, e);
	mlx_loop_hook(e->mlx, move, e);
	mlx_mouse_hook(e->win.adr, mouse_event, e);
	mlx_hook(e->win.adr, 6, (1L << 6), mouse_pos, e);
	mlx_hook(e->win.adr, 2, (1L << 0), key_press, e);
	mlx_hook(e->win.adr, 3, (1L << 1), key_release, e);
	mlx_loop(e->mlx);
}
