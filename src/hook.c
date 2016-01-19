/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 07:27:23 by scollon           #+#    #+#             */
/*   Updated: 2016/01/19 14:44:21 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_scene(t_env *e)
{
	t_rect	dir;

	dir = add_vector(e->cam.pos, e->cam.dir);
	mlx_pixel_put(e->mlx, e->win, e->cam.pos.x, e->cam.pos.y, 0xFF0000);
	mlx_pixel_put(e->mlx, e->win, e->cam.pos.x + e->cam.dir.x,
			e->cam.pos.y + e->cam.dir.y, 0x00FF00);
}

int		expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	draw_scene(e);
	return (1);
}
