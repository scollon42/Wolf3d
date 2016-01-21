/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 08:25:27 by scollon           #+#    #+#             */
/*   Updated: 2016/01/21 08:59:59 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECT_H
# define LIBVECT_H

# include <math.h>

# define PI	 3.1415926
# define D2R PI / 180
# define R2D 180 / PI

typedef struct  s_vectI
{
	int         x;
	int         y;
}               t_vectI;

typedef struct  s_vect
{
	float       x;
	float       y;
}				t_vect;


/*
**			Vectors creations
*/
t_vect 			vec_create(float x, float y);

/*
**			Vectors informations
*/
int				vec_cmp(const t_vect va, const t_vect vb);
float			vec_magnitude(const t_vect v);

/*
**			Vectors modifications
*/
t_vect			int_to_vec(const t_vectI i);
t_vectI			vec_to_int(const t_vect v);
t_vect			vec_norm(const t_vect v);
t_vect			vec_scale(const t_vect v, const float scale);
void    		vec_rotate(t_vect *v, float theta);

/*
**			Vectors math operation
*/
t_vect  		vec_add(const t_vect va, const t_vect vb);
t_vect			vec_sub(const t_vect va, const t_vect vb);
t_vect			vec_mult(const t_vect v, const float mult);
t_vect			vec_div(const t_vect v, const float div);


#endif
