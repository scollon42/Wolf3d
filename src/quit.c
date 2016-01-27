/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:09:16 by scollon           #+#    #+#             */
/*   Updated: 2016/01/27 16:43:16 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

void		quit(int error, t_env *e, char *msg)
{
	int	fd;

	fd = 1 + error;
	if (e != NULL)
	{
		e->img.adr != NULL ? mlx_destroy_image(e->mlx, e->img.adr) : 0;
		e->win.adr != NULL ? mlx_destroy_window(e->mlx, e->win.adr) : 0;
		e->skb.adr != NULL ? mlx_destroy_image(e->mlx, e->skb.adr) : 0;
		e->arg.map != NULL ? ft_strdel(&e->arg.map) : 0;
		e->map.map != NULL ? map_destroy(&e->map) : 0;
		e->tex.img != NULL ? texture_destroy(e) : 0;
		e->spr != NULL ? sprites_destroy(e) : 0;
		e->sound.music != NULL ? Mix_FreeMusic(e->sound.music) : 0;
		e->sound.fire != NULL ? Mix_FreeChunk(e->sound.fire) : 0;
		e->sound.empty != NULL ? Mix_FreeChunk(e->sound.empty) : 0;
		e->sound.reload != NULL ? Mix_FreeChunk(e->sound.reload) : 0;
		e->sound.run != NULL ? Mix_FreeChunk(e->sound.run) : 0;
		e->sound.walk != NULL ? Mix_FreeChunk(e->sound.walk) : 0;
		Mix_CloseAudio();
		ft_memdel((void**)&e);
	}
	if (msg != NULL)
		ft_putstr_fd(msg, fd);
	exit(0);
}
