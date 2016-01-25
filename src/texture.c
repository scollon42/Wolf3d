/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:19:45 by scollon           #+#    #+#             */
/*   Updated: 2016/01/25 17:00:30 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

void	texture_init(t_env *e)
{
	int		i;
	int		fd;
	char	*line;

	i = -1;
	if ((fd = open("./resources/texture.path", O_RDONLY)) == -1)
		quit(1, e, "Error : texture.path file doesn't exist\n");
	get_next_line(fd, &line);
	!(e->t_nb = ft_atoi(line)) ? quit(1, e, "Error : ivalid textures\n") : 0;
	ft_strdel(&line);
	if (!(e->tex = (t_spr*)malloc(sizeof(t_spr) * e->t_nb)))
		quit(1, e, "Error : can't load textures\n");
	while (get_next_line(fd, &line) > 0 && ++i <= e->t_nb)
	{
		if (!(e->tex[i].adr = mlx_xpm_file_to_image(e->mlx, line,
						&e->tex[i].w, &e->tex[i].h)))
			quit(1, e, "Error : can't load textures\n");
		if (!(e->tex[i].spr = mlx_get_data_addr(e->tex[i].adr, &e->tex[i].bpp,
						&e->tex[i].sl, &e->tex[i].endian)))
			quit(1, e, "Error : can't load textures\n");
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd) == -1 ? quit(1, e, "Error : closed failed\n") : 0;
}

void	texture_destroy(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->t_nb)
		mlx_destroy_image(e->mlx, e->tex[i].adr);
	free(e->tex);
	e->tex = NULL;
}
