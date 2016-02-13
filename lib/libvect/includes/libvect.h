/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 08:25:27 by scollon           #+#    #+#             */
/*   Updated: 2016/02/09 16:31:04 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECT_H
# define LIBVECT_H

# include <math.h>

# define PI	 3.1415926
# define D2R PI / 180
# define R2D 180 / PI
# define ABS(x) (x < 0 ? -x : x);

# define UP vec3_up()
# define RIGHT vec3_right()
# define FORWARD vec3_forward()

enum { X, Y, Z };

/*
**	2D vectors struct
*/

typedef struct	s_vecti
{
	int			x;
	int			y;
}				t_vecti;

typedef struct	s_vectd
{
	double		x;
	double		y;
}				t_vectd;

typedef struct	s_vect
{
	float		x;
	float		y;
}				t_vect;

/*
** 3D vectors struct
*/

typedef struct	s_vect3d
{
	double		x;
	double		y;
	double		z;
}				t_vect3d;

typedef struct	s_vecti3d
{
	int			x;
	int			y;
	int			z;
}				t_vecti3d;

/*
**	2D VECTOR HANDLES FUNCTIONS
*/

/*
**			Vectors creations
*/
t_vect			vec_create(float x, float y);

/*
**			Vectors informations
*/
int				vec_cmp(const t_vect va, const t_vect vb);
float			vec_magnitude(const t_vect v);

/*
**			Vectors modifications
*/
t_vect			int_to_vec(t_vecti i);
t_vecti			vec_to_int(const t_vect v);
t_vect			vec_norm(const t_vect v);
t_vect			vec_scale(const t_vect v, const float scale);
void			vec_rotate(t_vect *v, float theta);

/*
**			Vectors math operation
*/
t_vect			vec_add(const t_vect va, const t_vect vb);
t_vect			vec_sub(const t_vect va, const t_vect vb);
t_vect			vec_mult(const t_vect v, const float mult);
t_vect			vec_div(const t_vect v, const float div);

/*
**	3D VECTOR HANDLES FUNCTIONS
*/

t_vect3d		vec3_create(const double x, const double y, const double z);

t_vect3d		vec3_add(const t_vect3d v3a, const t_vect3d v3b);
t_vect3d		vec3_sub(const t_vect3d v3a, const t_vect3d v3b);
t_vect3d		vec3_mult(const t_vect3d v3a, const double mult);
t_vect3d		vec3_mult_vec(const t_vect3d v3a, const t_vect3d v3b);
t_vect3d		vec3_div(const t_vect3d v3a, const double div);

double			vec3_magnitude(t_vect3d v3);
t_vect3d		vec3_norm(t_vect3d v3);
t_vect3d		vec3_scale(t_vect3d v3, double scale);
double			vec3_dot_product(t_vect3d v3a, t_vect3d v3b);
t_vect3d		vec3_cross_product(const t_vect3d a, const t_vect3d b);
void			vec3_rotate(t_vect3d *vec, double theta, int axis);
t_vect3d        	vec3_clamp(t_vect3d v, const double min, const double max);

t_vect3d		vec3_up(void);
t_vect3d		vec3_right(void);
t_vect3d		vec3_forward(void);

#endif
