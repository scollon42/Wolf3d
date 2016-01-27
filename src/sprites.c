/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:44:08 by scollon           #+#    #+#             */
/*   Updated: 2016/01/27 07:42:11 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

static void	transparancy(t_spr *spr)
{
	int	x;
	int	y;
	int	pos;

	y = 0;
	while (y < spr->h)
	{
		x = 0;
		while (x < spr->w)
		{
			pos = ((x * spr->opp) + (y * spr->sl));
			if (spr->spr[pos] == (char)136 && spr->spr[pos + 1] == (char)0
					&& spr->spr[pos + 2] == (char)152)
				spr->spr[pos + 3] = 255;
			x++;
		}
		y++;
	}
}

static void	load_sprites(t_env *e, int i, char *line)
{
	if (!(e->spr[i].adr = mlx_xpm_file_to_image(e->mlx, line,
		&e->spr[i].w, &e->spr[i].h)))
	{
		ft_strdel(&line);
		e->s_nb = (i > e->s_nb ? e->s_nb : i);
		quit(1, e, "Failed to load sprites\n");
	}
	if (!(e->spr[i].spr = mlx_get_data_addr(e->spr[i].adr, &e->spr[i].bpp,
		&e->spr[i].sl, &e->spr[i].endian)))
	{
		ft_strdel(&line);
		e->s_nb = (i > e->s_nb ? e->s_nb : i);
		quit(1, e, "Failed to load sprites\n");
	}
	e->spr[i].opp = e->spr[i].bpp / 8;
	ft_strdel(&line);
	transparancy(&e->spr[i]);
}

void		sprites_destroy(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->s_nb)
		mlx_destroy_image(e->mlx, e->spr[i].adr);
	free(e->spr);
	e->spr = NULL;
}

void		sprites_init(t_env *e)
{
	int		i;
	int		fd;
	char	*line;

	i = -1;
	if ((fd = open("./resources/weapon.path", O_RDONLY)) == -1)
		quit(1, e, "Weapon.path file doesn't exist\n");
	get_next_line(fd, &line) == 0 ? quit(1, e, "Invalid path file\n") : 0;
	!(e->s_nb = ft_atoi(line)) ? quit(1, e, "Failed to load sprites\n") : 0;
	ft_strdel(&line);
	if (!(e->spr = (t_spr*)malloc(sizeof(t_spr) * e->s_nb)))
		quit(1, e, "Failed to load sprites\n");
	while (get_next_line(fd, &line) > 0 && ++i <= e->s_nb)
		load_sprites(e, i, line);
	ft_strdel(&line);
	if (i + 1 != e->s_nb)
	{
		e->s_nb = (i > e->s_nb ? e->s_nb : i);
		quit(1, e, "Invalid path file\n");
	}
	close(fd) == -1 ? quit(1, e, "Close() failed\n") : 0;
}

void		put_sprites(t_env *e)
{
	int		t;

	t = 0;
	if (e->cam.shoot > 0)
		e->cam.shoot -= 1;
	e->cam.shoot == 5 ? e->cam.shoot = 0 : 0;
	if (e->cam.shoot)
	{
		sprites_destroy(e);
		sprites_init(e);
	}
	mlx_put_image_to_window(e->mlx, e->win.adr, e->spr[e->cam.shoot].adr,
			e->win.w / 2 - e->spr[e->cam.shoot].w / 2,
			e->win.h - e->spr[e->cam.shoot].h);
	if (e->cam.shoot > 0)
		e->cam.shoot += 1;
}
