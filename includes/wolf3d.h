/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 08:52:24 by scollon           #+#    #+#             */
/*   Updated: 2016/01/19 17:15:02 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WOLF3D_H
#define WOLF3D_H

# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_rect
{
	float		x;
	float		y;
}				t_rect;

typedef	struct	s_mouse
{
	int			x;
	int			y;
}				t_mouse;

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

typedef	struct	s_cam
{
	t_rect		pos;
	t_rect		dir;
	t_rect		plan;
}				t_cam;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	t_rect		ws;
	t_cam		cam;
	t_mouse		mse;
	t_key		key;
	t_img		img;
}				t_env;

int		expose_hook(t_env *e);
int     move(t_env *e);
int		key_press(int kc, t_env *e);
int		key_release(int kc, t_env *e);
int		mouse_pos(int x, int y, t_env *e);

void	draw_scene(t_env *e);

void	img_pixel_put(t_env *e, int x, int y, int color);
void	draw_line(t_env *e, t_point src, t_point dst, int color);

t_rect  sub_vector(const t_rect vdst, const t_rect vsrc);
t_rect	add_vector(const t_rect vdst, const t_rect vsrc);
t_rect  scale_vector(const t_rect vdst, const float scale);
t_rect  norm_vector(const t_rect vector);
t_point	int_vector(const t_rect vector);
t_rect  mult_vector(const t_rect vector, const float mult);
void    rotate_vector(t_rect *v, float theta);
float	mag_vector(const t_rect vector);

t_env 	*init_env(void);
void	init_img(t_env *e);

#endif
