/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 07:38:13 by scollon           #+#    #+#             */
/*   Updated: 2016/01/22 08:44:45 by scollon          ###   ########.fr       */
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
	e->key.kup = kc == 13 ? 1 : 0;
	e->key.kdn = kc == 1 ? 1 : 0;
	e->key.klt = kc == 0 ? 1 : 0;
	e->key.krt = kc == 2 ? 1 : 0;
	return (1);
}

int	key_release(int kc, t_env *e)
{
	e->key.kup = kc == 13 ? 0 : 0;
	e->key.kdn = kc == 2 ? 0 : 0;
	e->key.klt = kc == 0 ? 0 : 0;
	e->key.krt = kc == 2 ? 0 : 0;
	return (1);
}
