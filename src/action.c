/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 07:52:47 by scollon           #+#    #+#             */
/*   Updated: 2016/01/27 16:31:02 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

static void		weapon(t_env *e)
{
	if (e->key.r == 1)
	{
		if (e->player.am == 0)
		{
			Mix_PlayChannel(2, e->sound.reload, 0);
			e->player.am = 10;
		}
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

static void		rotate(t_env *e)
{
	float	rot;

	e->key.a ? rot = 3.5 : 0;
	e->key.d ? rot = -3.5 : 0;
	if (e->key.a)
	{
		e->skb.pos.x -= 28;
		e->skb.pos.x < 0 ? e->skb.pos.x = 0 : 0;
	}
	else if (e->key.d)
	{
		e->skb.pos.x += 28;
		e->skb.pos.x > e->skb.w ? e->skb.pos.x = 10 : 0;
	}
	vec_rotate(&e->cam.dir, rot);
	vec_rotate(&e->cam.pln, rot);
	Mix_Pause(3);
}

static void		move(t_env *e)
{
	t_vect	tmp;
	t_vect	dir;
	t_vect	pln;

	tmp = e->cam.pos;
	if (e->key.w || e->key.s)
	{
		dir = vec_scale(e->cam.dir, e->cam.run);
		tmp = e->key.w == 1 ? vec_add(e->cam.pos, dir) : tmp;
		tmp = e->key.s == 1 ? vec_sub(e->cam.pos, dir) : tmp;
		e->cam.pos = e->map.map[(int)tmp.y][(int)tmp.x] == 0 ? tmp : e->cam.pos;
	}
	if (e->key.e || e->key.q)
	{
		pln = vec_scale(e->cam.pln, e->cam.run);
		tmp = e->key.e == 1 ? vec_add(e->cam.pos, pln) : tmp;
		tmp = e->key.q == 1 ? vec_sub(e->cam.pos, pln) : tmp;
		e->cam.pos = e->map.map[(int)tmp.y][(int)tmp.x] == 0 ? tmp : e->cam.pos;
	}
	e->key.a || e->key.d ? rotate(e) : 0;
	e->key.w || e->key.s || e->key.q || e->key.e ? Mix_Resume(3) : 0;
}

int				action(t_env *e)
{
	if (e->key.w || e->key.s || e->key.e || e->key.q || e->key.a || e->key.d)
		move(e);
	else
		Mix_Pause(3);
	e->cam.shoot || e->key.r ? weapon(e) : 0;
	e->cam.run = e->key.run == 1 ? 0.06 : 0.02;
	expose_hook(e);
	return (0);
}
