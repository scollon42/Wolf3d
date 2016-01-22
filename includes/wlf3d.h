/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlf3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:52:00 by scollon           #+#    #+#             */
/*   Updated: 2016/01/22 15:57:33 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WLF3D_H
# define WLF3D_H

# include <libft.h>
# include <libvect.h>
# include <math.h>
# include <stdlib.h>
# include <mlx.h>

# include <stdio.h> // tmp .h

typedef	struct	s_arg
{
	char		*map;
	int			fd;
	int			w;
	int			h;
}				t_arg;

typedef	struct	s_win
{
	void		*adr;
	int			w;
	int			h;
}				t_win;

typedef	struct	s_img
{
	void		*adr;
	char		*img;
	int			bpp;
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
}				t_cam;

typedef	struct	s_key
{
	int			kup;
	int			kdn;
	int			klt;
	int			krt;
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
	t_vectI		map;
	t_vectI		step;
	int			side;
	int			hit;
	int			wallc;
	float		cam;
	double		dist;
}				t_ray;

typedef struct	s_spr
{
	void		*adr;
	char		*spr;
	int			w;
	int			h;
	int			bpp;
	int			sl;
	int			endian;
}				t_spr;

typedef struct	s_env
{
	t_arg		arg;
	void		*mlx;
	t_win		win;
	t_img		img;
	t_cam		cam;
	t_key		key;
	t_vectI		mse;
	t_map		map;
	t_ray		ray;
	t_spr		spr;
}				t_env;

void			quit(int error, t_env *e, char *msg);

void			env_init(t_env *e);
void			img_init(t_env *e);
void			cam_init(t_env *e);
void			key_init(t_key *k);
void			map_init(t_env *e);

void			core(t_env *e);

void			render(t_env *e);
void			img_pixel_put(t_env *e, int x, int y, int color);

int				mouse_pos(int x, int y, t_env *e);
int				key_press(int kc, t_env *e);
int				key_release(int kc, t_env *e);

void			sprites_init(t_env *e);
void			put_sprites(t_env *e);

#endif
