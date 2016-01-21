/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 07:27:38 by scollon           #+#    #+#             */
/*   Updated: 2016/01/21 08:15:04 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_img(t_env *e)
{
	if (!(e->img.adr = mlx_new_image(e->mlx, e->ws.x, e->ws.y)))
		exit(0);
	e->img.img = mlx_get_data_addr(e->img.adr,
			&e->img.bpp, &e->img.sl, &e->img.endian);
}

void	generate_map(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (i == 0 || j == 0 || i == map->size - 1 || j == map->size - 1)
				map->map[i][j] = 4;
			else
				map->map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_map(t_map map)
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

	i = 0;
	e->map.size = 50;
	e->map.wall_h = 64;
	e->map.wall_s.x = 64;
	e->map.wall_s.y = 64;
	if (!(e->map.map = (int**)malloc(sizeof(int*) * e->map.size)))
		exit(0);
	while (i < e->map.size)
		if(!(e->map.map[i++] = (int*)malloc(sizeof(int) * e->map.size)))
			exit(0);
	generate_map(&e->map);
}

void	init_cam(t_env *e)
{
	e->cam.pos.x = e->ws.x / 2;
	e->cam.pos.y = e->ws.y / 2;
	e->cam.view = e->ws.x / 2;
	e->cam.fov = 60;
	e->cam.dir.x = 0;
	e->cam.dir.y = -fabs(e->cam.view / tan((e->cam.fov / 2)  * D2R));
	e->cam.plan.x = e->cam.view;
	e->cam.plan.y = 0;
	e->cam.r_ang = ((float)e->cam.fov) / (((float)e->cam.view));
	printf("%f\n", e->cam.r_ang);
	e->cam.h = e->map.wall_h / 2;
}

t_env	*init_env(void)
{
	t_env *e;

	if(!(e = (t_env *)malloc(sizeof(t_env))))
		exit(0);
	if(!(e->mlx = mlx_init()))
		exit(0);
	e->ws.x = 800;
	e->ws.y = 800;
	e->win = mlx_new_window(e->mlx, e->ws.x, e->ws.y, "WOLF3D @ 42");
	e->mse.x = e->cam.dir.x;
	e->mse.y = e->cam.dir.y;
	init_img(e);
	init_map(e);
	init_cam(e);
	return (e);
}
