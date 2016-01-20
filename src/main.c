/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 08:49:55 by scollon           #+#    #+#             */
/*   Updated: 2016/01/20 10:12:48 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(void)
{
	t_env	*e;

	e = init_env();
	mlx_hook(e->win, 6, (1L << 6), mouse_pos, e);
	mlx_hook(e->win, 2, (1L << 0), key_press, e);
	mlx_hook(e->win, 3, (1L << 1), key_release, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop_hook(e->mlx, move, e);
	mlx_loop(e->mlx);
	return (0);
}
