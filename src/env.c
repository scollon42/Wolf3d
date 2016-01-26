/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:30:23 by scollon           #+#    #+#             */
/*   Updated: 2016/01/26 16:51:19 by scollon          ###   ########.fr       */
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
	if (!(e->player.f.adr = mlx_xpm_file_to_image(e->mlx,
	"./resources/sprites/head.xpm", &e->player.f.w, &e->player.f.h)))
		quit (1, e, "Failed to laod sprites\n");
	if (!(e->player.f.spr = mlx_get_data_addr(e->player.f.adr, &e->player.f.bpp,
			&e->player.f.sl, &e->player.f.endian)))
		quit (1, e, "Failed to load sprites\n");
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
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
	Mix_AllocateChannels(4);
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
	Mix_PlayMusic(e->sound.music, -1);
}

void	env_init(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		quit(1, e, "Mlx init failed\n");
	e->win.w = e->arg.w;
	e->win.h = e->arg.h;
	e->win.adr = mlx_new_window(e->mlx, e->win.w, e->win.h, "WOLF3D @ 42");
	if (e->win.adr == NULL)
		quit(1, e, "Mlx failed to create window\n");
	img_init(e);
	key_init(&e->key);
	texture_init(e);
	e->tex.on = 0;
	map_init(e);
	cam_init(e);
	init_sound(e);
	sprites_init(e);
}
