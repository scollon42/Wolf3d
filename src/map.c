/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 07:50:25 by scollon           #+#    #+#             */
/*   Updated: 2016/01/25 16:09:41 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

static int	*fill_map(t_env *e, char **line)
{
	int		i;
	int		*map;
	char	**tab;

	i = 0;
	if (!(map = (int*)malloc(sizeof(int) * e->map.size)))
		quit(1, e, "Error : failed to load map\n");
	get_next_line(e->arg.fd, line);
	tab = ft_strsplit(*line, ' ');
	while (tab[i] != NULL)
	{
		if ((map[i] = ft_atoi(tab[i])) > 9)
			quit(1, e, "Error : invalid map file\n");
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return (map);
}

void		map_init(t_env *e)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(e->arg.fd, &line);
	if ((e->map.size = ft_atoi(line)) == 0)
		quit(1, e, "Error : failed to parse map file\n");
	free(line);
	if (!(e->map.map = (int**)malloc(sizeof(int*) * e->map.size)))
		quit(1, e, "Error : failed to load map\n");
	while (i < e->map.size)
	{
		e->map.map[i++] = fill_map(e, &line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if ((close(e->arg.fd)) == -1)
		quit(1, e, "Error : close() failed\n");
}
