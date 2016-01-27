/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 07:29:01 by scollon           #+#    #+#             */
/*   Updated: 2016/01/27 10:03:38 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

static void	aff_menu(t_env *e)
{
	char	*am;
	char	*hp;

	am = ft_itoa(e->player.am);
	hp = ft_itoa(e->player.hp);
	mlx_put_image_to_window(e->mlx, e->win.adr, e->player.f.adr, -1, 0);
	mlx_put_image_to_window(e->mlx, e->win.adr, e->player.s.adr,
			e->win.w / 2, e->win.h / 2 + e->player.s.h + 20);
	mlx_string_put(e->mlx, e->win.adr, e->player.f.w + 10, 10, 0xff0000, hp);
	mlx_string_put(e->mlx, e->win.adr, e->player.f.w + 10, 30, 0xff0000, am);
	ft_strdel(&am);
	ft_strdel(&hp);
}

int			expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win.adr);
	mlx_destroy_image(e->mlx, e->img.adr);
	img_init(e);
	render(e);
	mlx_put_image_to_window(e->mlx, e->win.adr, e->img.adr, 0, 0);
	put_sprites(e);
	aff_menu(e);
	return (0);
}

int			mouse_event(int btn, int x, int y, t_env *e)
{
	if (btn == 1)
		e->cam.shoot = 1;
	e->mse.x = x;
	e->mse.y = y;
	return (1);
}

void		core(t_env *e)
{
	Mix_PlayChannel(3, e->sound.run, -1);
	Mix_Pause(3);
	mlx_expose_hook(e->win.adr, expose_hook, e);
	mlx_loop_hook(e->mlx, action, e);
	mlx_mouse_hook(e->win.adr, mouse_event, e);
	mlx_hook(e->win.adr, 6, (1L << 6), mouse_pos, e);
	mlx_hook(e->win.adr, 2, (1L << 0), key_press, e);
	mlx_hook(e->win.adr, 3, (1L << 1), key_release, e);
	mlx_loop(e->mlx);
	Mix_FreeMusic(e->sound.music);
	Mix_CloseAudio();
}
