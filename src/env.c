/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:30:23 by scollon           #+#    #+#             */
/*   Updated: 2016/01/27 16:28:27 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf3d.h"

void	img_init(t_env *e)
{
	if (!(e->img.adr = mlx_new_image(e->mlx, e->win.w, e->win.h)))
		quit(1, e, "Mlx failed to create image");
	if (!(e->img.img = mlx_get_data_addr(e->img.adr, &e->img.bpp,
					&e->img.sl, &e->img.endian)))
		quit(1, e, "Mlx failed to create image");
	e->img.opp = e->img.bpp / 8;
}

void	cam_init(t_env *e)
{
	e->cam.pos = find_empty_pos(e);
	e->cam.dir = vec_create(0, 1);
	e->cam.pln = vec_create(1, 0);
	e->cam.run = 0.05;
	e->cam.shoot = 0;
	e->player.hp = 100;
	e->player.wp = 0;
	e->player.am = 10;
	if (!(e->player.s.adr = mlx_xpm_file_to_image(e->mlx,
	"./resources/sprites/sights.xpm", &e->player.s.w, &e->player.s.h)))
		quit(1, e, "Failed to load sprites\n");
	if (!(e->player.s.spr = mlx_get_data_addr(e->player.s.adr, &e->player.s.bpp,
			&e->player.s.sl, &e->player.s.endian)))
		quit(1, e, "Failed to load sprites\n");
}

void	key_init(t_key *k)
{
	k->w = 0;
	k->s = 0;
	k->a = 0;
	k->d = 0;
	k->q = 0;
	k->e = 0;
	k->run = 1;
}

void	init_sound(t_env *e)
{
	if (SDL_Init(SDL_INIT_AUDIO) == -1)
		quit(1, e, "Failed to load sounds resources\n");
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
		quit(1, e, "Failed to load sounds resources\n");
	if (Mix_AllocateChannels(4) == -1)
		quit(1, e, "You killed my SDL\n");
	if (!(e->sound.music = Mix_LoadMUS("resources/sounds/son.mp3")))
		quit(1, e, "Failed to load sounds resources\n");
	if (!(e->sound.fire = Mix_LoadWAV("resources/sounds/fire.wav")))
		quit(1, e, "Failed to load sounds resources\n");
	if (!(e->sound.reload = Mix_LoadWAV("resources/sounds/reload.wav")))
		quit(1, e, "Failed to load sounds resources\n");
	if (!(e->sound.empty = Mix_LoadWAV("resources/sounds/empty.wav")))
		quit(1, e, "Failed to load sounds resources\n");
	if (!(e->sound.run = Mix_LoadWAV("resources/sounds/run.wav")))
		quit(1, e, "Failed to load sounds resources\n");
	if (!(e->sound.walk = Mix_LoadWAV("resources/sounds/walk.wav")))
		quit(1, e, "Failed to load sounds resources\n");
	if (Mix_PlayMusic(e->sound.music, -1) == -1)
		quit(1, e, "Failed to load sounds resources\n");
}

void	env_init(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		quit(1, e, "Mlx init failed\n");
	e->win.w = e->arg.w;
	e->win.h = e->arg.h;
	e->win.h2 = e->win.h / 2;
	e->win.adr = mlx_new_window(e->mlx, e->win.w, e->win.h, "WOLF3D @ 42");
	if (e->win.adr == NULL)
		quit(1, e, "Mlx failed to create window\n");
	img_init(e);
	key_init(&e->key);
	texture_init(e);
	e->tex.on = 1;
	map_init(e);
	cam_init(e);
	sprites_init(e);
	init_sound(e);
}
