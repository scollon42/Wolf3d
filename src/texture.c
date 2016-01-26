/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:19:45 by scollon           #+#    #+#             */
/*   Updated: 2016/01/26 15:45:16 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

static void	load_texture(t_env *e, int i, char *line)
{
	int		err;

	err = 0;
	if (!(e->tex.img[i].adr = mlx_xpm_file_to_image(e->mlx, line,
		&e->tex.img[i].w, &e->tex.img[i].h)))
	{
		ft_strdel(&line);
		e->t_nb = (i > e->t_nb ? e->t_nb : i);
		quit(1, e, "Can't load textures\n");
	}
	if (!(e->tex.img[i].spr = mlx_get_data_addr(e->tex.img[i].adr,
		&e->tex.img[i].bpp, &e->tex.img[i].sl, &e->tex.img[i].endian)))
	{
		ft_strdel(&line);
		e->t_nb = (i > e->t_nb ? e->t_nb : i);
		quit(1, e, "Can't load textures\n");
	}
	ft_strdel(&line);
}

void		texture_destroy(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->t_nb)
		mlx_destroy_image(e->mlx, e->tex.img[i].adr);
	free(e->tex.img);
	e->tex.img = NULL;
}

void		texture_init(t_env *e)
{
	int		i;
	int		fd;
	char	*line;

	i = -1;
	if ((fd = open("./resources/texture.path", O_RDONLY)) == -1)
		quit(1, e, "Texture.path file doesn't exist\n");
	get_next_line(fd, &line) == 0 ? quit(1, e, "Invalid path file\n") : 0;
	!(e->t_nb = ft_atoi(line)) ? quit(1, e, "Invalid textures\n") : 0;
	ft_strdel(&line);
	if (!(e->tex.img = (t_spr*)malloc(sizeof(t_spr) * e->t_nb)))
		quit(1, e, "Can't load textures\n");
	while (get_next_line(fd, &line) > 0 && ++i <= e->t_nb)
		load_texture(e, i, line);
	ft_strdel(&line);
	if (i + 1 != e->t_nb)
	{
		e->t_nb = (i > e->t_nb ? e->t_nb : i);
		quit(1, e, "Invalid path file\n");
	}
	close(fd) == -1 ? quit(1, e, "Close() failed\n") : 0;
}
