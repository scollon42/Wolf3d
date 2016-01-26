/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:09:16 by scollon           #+#    #+#             */
/*   Updated: 2016/01/26 07:43:18 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

static void	destroy_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void**)&map->map[i]);
		i++;
	}
	ft_memdel((void**)map->map);
}

void		quit(int error, t_env *e, char *msg)
{
	int	fd;

	fd = 1 + error;
	if (e != NULL)
	{
		e->img.adr != NULL ? mlx_destroy_image(e->mlx, e->img.adr) : 0;
		e->win.adr != NULL ? mlx_destroy_window(e->mlx, e->win.adr) : 0;
		ft_strdel(&e->arg.map);
		destroy_map(&e->map);
		e->tex.img != NULL ? texture_destroy(e) : 0;
		e->spr != NULL ? sprites_destroy(e) : 0;
		e->sound.music != NULL ? Mix_FreeMusic(e->sound.music) : 0;
		e->sound.fire != NULL ? Mix_FreeChunk(e->sound.fire) : 0;
		Mix_CloseAudio();
		ft_memdel((void**)&e);
	}
	if (msg != NULL)
		ft_putstr_fd(msg, fd);
	exit(0);
}
