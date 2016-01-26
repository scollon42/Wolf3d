/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:44:08 by scollon           #+#    #+#             */
/*   Updated: 2016/01/26 08:12:38 by scollon          ###   ########.fr       */
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
			pos = ((x * spr->bpp / 8) + (y * spr->sl));
			if (spr->spr[pos] == (char)136 && spr->spr[pos + 1] == (char)0
				&& spr->spr[pos + 2] == (char)152)
				spr->spr[pos + 3] = 255;
			x++;
		}
		y++;
	}
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

void	sprites_init(t_env *e)
{
	int		i;
	int		fd;
	char	*line;

	i = -1;
	if ((fd = open("./resources/weapon.path", O_RDONLY)) == -1)
		quit(1, e, "Error : weapon.path file doesn't exist\n");
	get_next_line(fd, &line);
	!(e->s_nb = ft_atoi(line)) ? quit(1, e, "Error : can't loadsprites\n") : 0;
	ft_strdel(&line);
	if (!(e->spr = (t_spr*)malloc(sizeof(t_spr) * e->s_nb)))
		quit(1, e, "Error : failed to load sprites\n");
	while (get_next_line(fd, &line) > 0 && ++i <= e->s_nb)
	{
		if (!(e->spr[i].adr = mlx_xpm_file_to_image(e->mlx, line,
			&e->spr[i].w, &e->spr[i].h)))
			quit(1, e, "Error : failed to load sprites\n");
		if (!(e->spr[i].spr = mlx_get_data_addr(e->spr[i].adr, &e->spr[i].bpp,
						&e->spr[i].sl, &e->spr[i].endian)))
			quit(1, e, "Error : failed to load sprites\n");
		ft_strdel(&line);
		transparancy(&e->spr[i]);
	}
	ft_strdel(&line);
	close(fd) == -1 ? quit(1, e, "Error : closed failed\n") : 0;
}

void	put_sprites(t_env *e)
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
