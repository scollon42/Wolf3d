/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 08:52:24 by scollon           #+#    #+#             */
/*   Updated: 2016/01/20 14:11:33 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WOLF3D_H
#define WOLF3D_H

# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define D2R 3.1415926 / 180

typedef	struct	s_vectI
{
	int			x;
	int			y;
}				t_vectI;

typedef	struct	s_vect
{
	float		x;
	float		y;
}				t_vect;

typedef	struct	s_key
{
	int			ku;
	int			kd;
	int			kl;
	int			kr;
}				t_key;

typedef	struct 	s_img
{
	void		*adr;
	char		*img;
	int			endian;
	int			bpp;
	int			sl;
}				t_img;

typedef	struct	s_map
{

	size_t		size;
	int			**map;
	int			wall_h;
	t_vectI		wall_s;
}				t_map;

typedef	struct	s_cam
{
	t_vect		pos;
	t_vect		dir;
	t_vect		plan;
	int			view;
	int			fov;
	int			h;
	float		r_ang;
}				t_cam;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	t_vectI		ws;
	t_vectI		mse;
	t_cam		cam;
	t_key		key;
	t_img		img;
	t_map		map;
}				t_env;

int		expose_hook(t_env *e);
int     move(t_env *e);
int		key_press(int kc, t_env *e);
int		key_release(int kc, t_env *e);
int		mouse_pos(int x, int y, t_env *e);

void	draw_scene(t_env *e);
void	raycast(t_env *e);

void	img_pixel_put(t_env *e, int x, int y, int color);
void	draw_line(t_env *e, t_vectI src, t_vectI dst, int color);

t_vect	vec_create(float x, float y);
t_vectI	vec_to_int(const t_vect v);
t_vect  int_to_vec(const t_vectI i);
int		vec_cmp(const t_vect va, const t_vect vb);
float	vec_magnitude(const t_vect v);
void    vec_rotate(t_vect *v, float theta);
t_vect  vec_add(const t_vect va, const t_vect vb);
t_vect	vec_sub(const t_vect va, const t_vect vb);
t_vect	vec_mult(const t_vect v, const float mult);
t_vect	vec_scale(const t_vect v, const float scale);
t_vect	vec_norm(const t_vect v);

t_env 	*init_env(void);
void	init_img(t_env *e);

#endif
