/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 08:49:55 by scollon           #+#    #+#             */
/*   Updated: 2016/01/21 15:50:51 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	read_arg(t_env *e, int ac, char **av)
{
	if (ac == 2)
	{
		if (!(e->arg.map = ft_strdup(av[1])))
			exit(0);
	}
	else
		e->arg.map = ft_strdup("ressources/map.wf3d");
}

int		main(int ac, char **av)
{
	t_env	*e;

	//system("clear"); // tmp main.c
	e = init_env();
	read_arg(e, ac, av);
	mlx_hook(e->win, 6, (1L << 6), mouse_pos, e);
	mlx_hook(e->win, 2, (1L << 0), key_press, e);
	mlx_hook(e->win, 3, (1L << 1), key_release, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop_hook(e->mlx, move, e);
	mlx_loop(e->mlx);
	return (0);
}
