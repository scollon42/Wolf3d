/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 07:26:55 by scollon           #+#    #+#             */
/*   Updated: 2016/01/20 09:45:57 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		mouse_pos(int x, int y, t_env *e)
{
	e->mse.x = x;
	e->mse.y = y;
	return (1);
}

int		key_press(int kc, t_env *e)
{
	int	x;
	int	y;

	if (kc == 53)
	{
		free(e->mlx);
		exit(0);
	}
	e->key.ku = (kc == 126 ? 1 : 0);
	e->key.kd = (kc == 125 ? 1 : 0);
	e->key.kl = (kc == 123 ? 1 : 0);
	e->key.kr = (kc == 124 ? 1 : 0);
	return (1);
}

int		key_release(int kc, t_env *e)
{
	e->key.ku = (kc == 126 ? 0 : 0);
	e->key.kd = (kc == 125 ? 0 : 0);
	e->key.kl = (kc == 123 ? 0 : 0);
	e->key.kr = (kc == 124 ? 0 : 0);
	return (1);
}
