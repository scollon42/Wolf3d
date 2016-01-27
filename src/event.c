/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 07:38:13 by scollon           #+#    #+#             */
/*   Updated: 2016/01/27 15:43:08 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

int	key_press(int kc, t_env *e)
{
	kc == 53 ? quit(0, e, NULL) : 0;
	kc == 13 || kc == 126 ? e->key.w = 1 : 0;
	kc == 1 || kc == 125 ? e->key.s = 1 : 0;
	kc == 0 || kc == 123 ? e->key.a = 1 : 0;
	kc == 2 || kc == 124 ? e->key.d = 1 : 0;
	kc == 12 ? e->key.q = 1 : 0;
	kc == 14 ? e->key.e = 1 : 0;
	kc == 15 ? e->key.r = 1 : 0;
	kc == 49 ? e->cam.shoot = 1 : 0;
	kc == 17 && e->tex.on == 0 ? e->tex.on = 2 : 0;
	kc == 17 && e->tex.on == 1 ? e->tex.on = 0 : 0;
	e->tex.on == 2 ? e->tex.on = 1 : 0;
	e->cam.run = e->tex.on == 1 ? 0.09 : 0.05;
	if (kc == 257 && e->key.run == 1)
	{
		Mix_PlayChannel(3, e->sound.walk, -1);
		e->key.run = 0;
	}
	else if (kc == 257 && e->key.run == 0)
	{
		Mix_PlayChannel(3, e->sound.run, -1);
		e->key.run = 1;
	}
	return (1);
}

int	key_release(int kc, t_env *e)
{
	kc == 13 || kc == 126 ? e->key.w = 0 : 0;
	kc == 1 || kc == 125 ? e->key.s = 0 : 0;
	kc == 0 || kc == 123 ? e->key.a = 0 : 0;
	kc == 2 || kc == 124 ? e->key.d = 0 : 0;
	kc == 12 ? e->key.q = 0 : 0;
	kc == 14 ? e->key.e = 0 : 0;
	return (1);
}
