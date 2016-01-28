/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:01:47 by scollon           #+#    #+#             */
/*   Updated: 2016/01/28 08:17:05 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

static void	aff_help(t_env *e)
{
	ft_putstr("\n\033[1;32mUsage :\033[0m \033[1m./wolf3d");
	ft_putendl(" [-m file.wf] [-w window width] [-h window height]\033[0m\n");
	ft_putendl("\033[1mOptions :\033[0m");
	ft_putendl("        -m     : set map file");
	ft_putendl("        -w     : set windows width");
	ft_putendl("        -h     : set windows height");
	ft_putendl("        --help : print help");
	ft_putendl("\033[1mHow to use :\033[0m");
	ft_putendl("	Use wasd or arrow to move");
	ft_putendl("	Use space to shoot");
	ft_putendl("	Use r to reload");
	ft_putendl("	Use t set textures on");
	ft_putendl("	Use ESC to quit");
	quit(0, e, NULL);
}

static void	read_arg(t_env *e, int ac, char **av)
{
	int		i;

	i = 0;
	e->arg.w = 0;
	e->arg.h = 0;
	e->arg.map = NULL;
	if (ac == 2 && ft_strcmp(av[1], "--help") == 0)
		aff_help(e);
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-m") == 0)
			e->arg.map = ft_strdup(av[i + 1]);
		if (ft_strcmp(av[i], "-w") == 0)
			e->arg.w = ft_atoi(av[i + 1]);
		if (ft_strcmp(av[i], "-h") == 0)
			e->arg.h = ft_atoi(av[i + 1]);
	}
	e->arg.map == NULL ? e->arg.map = ft_strdup("./resources/map/map.wf") : 0;
	e->arg.w <= 200 || e->arg.w >= 200 ? e->arg.w = 800 : 0;
	e->arg.h <= 200 || e->arg.h >= 200 ? e->arg.h = 600 : 0;
	if ((e->arg.fd = open(e->arg.map, O_RDWR)) == -1)
		quit(1, e, "Failed to load map file\n");
	e->arg.map != NULL ? ft_strdel(&e->arg.map) : 0;
}

int			main(int ac, char **av)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		quit(1, NULL, "Environnement can't be create\n");
	read_arg(e, ac, av);
	env_init(e);
	core(e);
	quit(0, e, NULL);
	return (0);
}
