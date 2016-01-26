/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 07:50:25 by scollon           #+#    #+#             */
/*   Updated: 2016/01/26 15:40:58 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

void		map_destroy(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->size)
	{
		map->map[i] == NULL ? ft_memdel((void**)&map->map[i]) : 0;
		i++;
	}
	free(map->map);
	map->map = NULL;
}

t_vect		find_empty_pos(t_env *e)
{
	int			i;
	int			j;
	t_vect		pos;

	j = 1;
	i = 1;
	pos.x = 0;
	pos.y = 0;
	while (j < e->map.size)
	{
		i == e->map.size ? j++ : 0;
		i == e->map.size ? i = 0 : 0;
		if (e->map.map[j][i] == 0)
			return (vec_create(j + 0.5, i + 0.5));
		i++;
	}
	quit(1, e, "No place for player position\n");
	return (pos);
}

static void	map_correction(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++j < map->size && ++i < map->size)
	{
		if (map->map[j][0] == 0)
			map->map[j][0] = 1;
		if (map->map[j][map->size - 1] == 0)
			map->map[j][map->size - 1] = 1;
		if (map->map[0][i] == 0)
			map->map[0][i] = 1;
		if (map->map[map->size - 1][i] == 0)
			map->map[map->size - 1][i] = 1;
	}
}

static int	*fill_map(t_env *e, char **line)
{
	int		i;
	int		*map;
	char	**tab;

	i = 0;
	if (get_next_line(e->arg.fd, line) == 0)
	{
		e->map.size = 0;
		quit(1, e, "Invalid map file\n");
	}
	if (!(map = (int*)malloc(sizeof(int) * e->map.size)))
		quit(1, e, "Failed to load map\n");
	tab = ft_strsplit(*line, ' ');
	while (tab[i] != NULL)
	{
		if ((map[i] = ft_atoi(tab[i])) > e->t_nb)
			quit(1, e, "Invalid map file\n");
		ft_strdel(&tab[i]);
		i++;
	}
	i != e->map.size ? quit(1, e, "Invalid map file\n") : 0;
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
	if ((e->map.size = ft_atoi(line)) < 3)
		quit(1, e, "Failed to parse map file\n");
	free(line);
	if (!(e->map.map = (int**)malloc(sizeof(int*) * e->map.size)))
		quit(1, e, "Failed to load map\n");
	while (i < e->map.size)
	{
		e->map.map[i++] = fill_map(e, &line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if ((close(e->arg.fd)) == -1)
		quit(1, e, "Close() failed\n");
	map_correction(&e->map);
}
