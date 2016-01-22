/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:09:16 by scollon           #+#    #+#             */
/*   Updated: 2016/01/22 08:15:42 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

static void	destroy_map(t_map *map)
{
	size_t	i;

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
		ft_memdel((void**)&e);
	}
	if (msg != NULL)
		ft_putstr_fd(msg, fd);
	exit(0);
}
