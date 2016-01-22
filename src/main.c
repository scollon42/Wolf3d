/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:01:47 by scollon           #+#    #+#             */
/*   Updated: 2016/01/22 11:24:54 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

static void	aff_help(t_env *e)
{
	ft_putendl("Here we'll be able to help you. Soon.. I promise.");
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
	e->arg.map == NULL ? e->arg.map = ft_strdup("./ressources/map.wf") : 0;
	e->arg.w == 0 ? e->arg.w = 800 : 0;
	e->arg.h == 0 ? e->arg.h = 800 : 0;
	if ((e->arg.fd = open(e->arg.map, O_RDWR)) == -1)
		quit(1, e, "Error : failed to load map file\n");
	ft_strdel(&e->arg.map);
}

int			main(int ac, char **av)
{
	t_env	*e;

	system("clear"); // tmp
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		quit(1, NULL, "Error : environnement can't be create\n");
	read_arg(e, ac, av);
	env_init(e);
	core(e);
	quit(0, e, NULL);
	return (0);
}
