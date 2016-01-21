/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:46:57 by scollon           #+#    #+#             */
/*   Updated: 2016/01/21 15:50:56 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	fill_map(int *map_line, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != 0)
	{
		if (line[i] == ',' || ft_isdigit(line[i]))
		{
			if (ft_isdigit(line[i]))
				map_line[j++] = ft_atoi(&line[i]);
		}
		else
			exit (0);
		i++;
	}
}


static int	**allocate_map(size_t size)
{
	size_t	i;
	int		**map;

	i = 0;
	if (!(map = (int**)malloc(sizeof(int*) * size)))
		exit(0);
	while (i < size)
		if(!(map[i++] = (int*)malloc(sizeof(int) * size)))
			exit(0);
	return (map);
}

static void	generate_map(int fd, t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(fd, &line);
	printf("coucou\n");
	if ((map->size = ft_atoi(line) < 16))
		exit(0);
	map->map = allocate_map(map->size);
	while (get_next_line(fd, &line) > 0)
	{
		fill_map(map->map[i], line);
		free(line);
		i++;
	}
}

static void	print_map(t_map map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map.size)
	{
		j = 0;
		while (j < map.size)
		{
			ft_putnbr(map.map[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	init_map(t_env *e)
{
	int		i;
	int		fd;

	i = 0;
	if ((fd = open(e->arg.map, O_RDWR)) == -1)
	{
		printf("%d\n", fd);
		exit(0);
	}
	generate_map(fd, &e->map);
	if (close(fd) == -1)
		exit(0);
	print_map(e->map);
}
