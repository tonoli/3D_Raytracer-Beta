/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 22:20:40 by itonoli-          #+#    #+#             */
/*   Updated: 2017/09/05 20:10:35 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rt.h"

int solve_quadratic(t_vect va, t_vect vb, t_vect vc, t_vect rayon)
{
	
}

float		dot_product(t_vect a, t_vect b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vect		add(t_vect a, t_vect b)
{
	t_vect v;

	v = init_vect(a.x + b.x, a.y + b.y, a.z + b.z);
	return (v);
}

t_vect		sub(t_vect a, t_vect b)
{
	t_vect	v;

	v = init_vect(a.x - b.x, a.y - b.y, a.z - b.z);
	return (v);
}


/*
 * Now if need to build a function that will return 1 if the ray intersects an
 * object or 0 if not then thanks to that we will clor or black pixel
 */

int		intersect(t_env *e)
{
	t_vect l;

	l = e->orign - center;
	if (!(solveQuadratic(e->a, e->b, e->c, e->t0, e->t1)))
		return (0);


}
