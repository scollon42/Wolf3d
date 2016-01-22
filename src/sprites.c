/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:44:08 by scollon           #+#    #+#             */
/*   Updated: 2016/01/22 15:45:47 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

void	sprites_init(t_env *e)
{
	int	x;
	int	y;
	int	pos;

	y = 0;
	if (!(e->spr.adr = mlx_xpm_file_to_image(e->mlx,
	"./ressources/sprites/weapons/pistol1.xpm", &e->spr.w, &e->spr.h)))
		quit(1, e, "Error : failed to load sprites\n");
	if (!(e->spr.spr = mlx_get_data_addr(e->spr.adr,&e->spr.bpp,
								&e->spr.sl, &e->spr.endian)))
		quit(1, e, "Error : failed to load sprites\n");
	while (y < e->spr.h)
	{
		x = 0;
		while (x < e->spr.w)
		{
			pos = ((x * e->spr.bpp / 8) + (y * e->spr.sl));
			if (e->spr.spr[pos] == (char)136 && e->spr.spr[pos+1] == (char) 0 &&e->spr.spr[pos + 2] == (char)152)
				e->spr.spr[pos + 3] = 255;
			x++;
		}
		y++;
	}
}

void	put_sprites(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win.adr, e->spr.adr,
				e->win.w / 2 - e->spr.w, e->win.h - e->spr.h);
}
