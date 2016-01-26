/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 07:52:47 by scollon           #+#    #+#             */
/*   Updated: 2016/01/26 09:23:44 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

static void		weapon(t_env *e)
{
	if (e->key.r == 1 && e->player.am == 0)
	{
		Mix_PlayChannel(2, e->sound.reload, 0);
		e->player.am = 10;
		e->key.r = 0;
	}
	if (e->player.am > 0)
	{
		e->cam.shoot == 1 ? e->player.am -= 1 : 0;
		e->cam.shoot == 1 ? Mix_PlayChannel(2, e->sound.fire, 0) : 0;
		e->cam.shoot > 0 ? e->cam.shoot++ : 0;
	}
	else
	{
		e->cam.shoot = 0;
		Mix_PlayChannel(2, e->sound.empty, 0);
	}
}

static void		move(t_env *e)
{
	float   rot;
	t_vect  tmp;
	t_vect	dir;
	t_vect	pln;

	tmp = e->cam.pos;
	dir = vec_scale(e->cam.dir, e->cam.run);
	pln = vec_scale(e->cam.pln, e->cam.run);
	if (e->key.w)
		tmp = vec_add(e->cam.pos, dir);
	if (e->key.s)
		tmp = vec_sub(e->cam.pos, dir);
	if	(e->key.e)
		tmp = vec_add(e->cam.pos, pln);
	if (e->key.q)
		tmp = vec_sub(e->cam.pos, pln);
	e->key.a ? rot = -2.5 : 0;
	e->key.d ? rot = 2.5 : 0;
	vec_rotate(&e->cam.dir, rot);
	vec_rotate(&e->cam.pln, rot);
	e->cam.pos = e->map.map[(int)tmp.y][(int)tmp.x] == 0 ? tmp : e->cam.pos;
	Mix_Resume(3);
}

int         	action(t_env *e)
{
	if (e->key.w || e->key.s || e->key.e || e->key.q || e->key.a || e->key.d)
		move(e);
	else
		Mix_Pause(3);
	e->cam.shoot || e->key.r ? weapon(e) : 0;
	e->cam.run = e->key.run == 1 ? 0.05 : 0.02;
	expose_hook(e);
	return (0);
}
