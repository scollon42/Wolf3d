/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 07:38:13 by scollon           #+#    #+#             */
/*   Updated: 2016/01/22 12:05:06 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

int	mouse_pos(int x, int y, t_env *e)
{
	e->mse.x = x;
	e->mse.y = y;
	return (1);
}

int	key_press(int kc, t_env *e)
{
	kc == 53 ? quit(0, e, NULL) : 0;
	kc == 13 ? e->key.kup = 1 : 0;
	kc == 1 ? e->key.kdn = 1 : 0;
	kc == 0 ? e->key.klt = 1 : 0;
	kc == 2 ? e->key.krt = 1 : 0;
	if (kc == 257 && e->key.run == 1)
		e->key.run = 0;
	else if (kc == 257 && e->key.run == 0)
		e->key.run = 1;
	return (1);
}

int	key_release(int kc, t_env *e)
{
	kc == 13 ? e->key.kup = 0 : 0;
	kc == 1 ? e->key.kdn = 0 : 0;
	kc == 0 ? e->key.klt = 0 : 0;
	kc == 2 ? e->key.krt = 0 : 0;
	return (1);
}
