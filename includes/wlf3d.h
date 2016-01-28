/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlf3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:52:00 by scollon           #+#    #+#             */
/*   Updated: 2016/01/28 10:15:34 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WLF3D_H
# define WLF3D_H

# include <libft.h>
# include <libvect.h>
# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <SDL.h>
# include <SDL_mixer.h>

# define ABS(x) (x < 0 ? -x : x);

typedef	struct	s_arg
{
	char		*map;
	int			fd;
}				t_arg;

typedef	struct	s_win
{
	void		*adr;
	int			w;
	int			h;
	int			h2;
}				t_win;

typedef	struct	s_img
{
	void		*adr;
	char		*img;
	int			bpp;
	int			opp;
	int			sl;
	int			endian;
}				t_img;

typedef	struct	s_cam
{
	t_vect		pos;
	t_vect		dir;
	t_vect		pln;
	float		cam;
	float		run;
	short		shoot;
}				t_cam;

typedef	struct	s_key
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			q;
	int			e;
	int			r;
	int			b;
	int			run;
}				t_key;

typedef	struct	s_map
{
	int			**map;
	size_t		size;
}				t_map;

typedef	struct	s_ray
{
	t_vect		pos;
	t_vect		dir;
	t_vect		len;
	t_vect		a;
	t_vecti		map;
	t_vecti		step;
	int			side;
	int			hit;
	int			wallc;
	int			x;
	float		cam;
	float		dist;
}				t_ray;

typedef	struct	s_snd
{
	Mix_Music	*music;
	Mix_Chunk	*fire;
	Mix_Chunk	*empty;
	Mix_Chunk	*reload;
	Mix_Chunk	*run;
	Mix_Chunk	*walk;
}				t_snd;

typedef struct	s_spr
{
	void		*adr;
	char		*spr;
	int			w;
	int			h;
	int			h2;
	int			bpp;
	int			opp;
	int			sl;
	int			endian;
	int			index;
}				t_spr;

typedef struct	s_tex
{
	t_spr		*img;
	t_vecti		tex;
	int			index;
	short		on;
	int			color;
	float		wall;
}				t_tex;

typedef struct	s_flo
{
	t_spr		img;
	t_vect		wall;
	t_vect		cur;
	t_vecti		tex;
	float		wei;
	float		dist;
	int			color;

}				t_flo;

typedef struct	s_skb
{
	void		*adr;
	char		*skb;
	int			w;
	int			h;
	int			bpp;
	int			opp;
	int			sl;
	int			endian;
	t_vecti		pos;
}				t_skb;

typedef struct	s_ply
{
	t_spr		s;
	short		hp;
	short		wp;
	short		am;
}				t_ply;

typedef struct	s_env
{
	t_arg		arg;
	void		*mlx;
	t_win		win;
	t_img		img;
	t_cam		cam;
	t_ply		player;
	t_key		key;
	t_map		map;
	t_ray		ray;
	t_spr		*spr;
	t_tex		tex;
	t_skb		skb;
	t_flo		flo;
	short		s_nb;
	short		t_nb;
	t_snd		sound;
}				t_env;

void			quit(int error, t_env *e, char *msg);

void			env_init(t_env *e);
void			img_init(t_env *e);
void			cam_init(t_env *e);
void			key_init(t_key *k);
void			init_sound(t_env *e);

void			map_init(t_env *e);
void			map_destroy(t_map *map);
t_vect			find_empty_pos(t_env *e);

void			texture_init(t_env *e);
void			texture_destroy(t_env *e);

void			sprites_init(t_env *e);
void			put_sprites(t_env *e);
void			sprites_destroy(t_env *e);

void			core(t_env *e);
int				action(t_env *e);
int				expose_hook(t_env *e);
int				key_press(int kc, t_env *e);
int				key_release(int kc, t_env *e);

void			img_pixel_put(t_env *e, int x, int y, int color);
int				rgb_to_hex(int r, int g, int b);

void			render(t_env *e);
void			skybox_draw(t_env *e);
void			raycast_init(t_env *e, int x);
void			raycast_calc(t_env *e);
void			raycast_cast(t_env *e);
void			raycast_dist(t_env *e);
void			raycast_draw(t_env *e, int x);
void			raycast_nu(t_env *e, int ds, int de, int hl);
void			raycast_tx(t_env *e, int ds, int de, int hl);
void			raycast_tx_draw(t_env *e, int ds, int de, int hl);

#endif
