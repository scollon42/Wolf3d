/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 08:52:24 by scollon           #+#    #+#             */
/*   Updated: 2016/01/19 14:45:24 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WOLF3D_H
#define WOLF3D_H

# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct	s_rect
{
	double		x;
	double		y;
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
}				t_env;

int		expose_hook(t_env *e);
int		key_press(int kc, t_env *e);
int		key_release(int kc, t_env *e);
int		mouse_pos(int x, int y, t_env *e);
void	draw_scene(t_env *e);
void	draw_line(t_env *e, t_rect src, t_rect dst);
t_rect	add_vector(const t_rect vdst, const t_rect vsrc);
void    rotate_vector(t_rect *v, float theta);
t_env 	*init_env(void);

#endif
