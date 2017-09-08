/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 22:20:40 by itonoli-          #+#    #+#             */
/*   Updated: 2017/09/08 15:06:54 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rt.h"

void	distance(t_env *e, t_obj *obj, t_vect ray)
{
	float	dist;

	obj->h1 = (-obj->b - sqrt(obj->delta)) / (2.0 * obj->a);
	obj->h2 = (-obj->b + sqrt(obj->delta)) / (2.0 * obj->a);
	obj->h = (obj->h1 > obj->h2) ? obj->h2 : obj->h1;
	obj->hit = v_add(e->camera.o, v_mult(ray, obj->h));
	dist = sqrt(dot_product(
		v_sub(e->camera.o, obj->hit), v_sub(e->camera.o, obj->hit)));
	obj->dist = dist;
}

void	sphere_distance(t_env *e, t_vect ray, t_obj *obj)
{
	t_vect	cam;

	cam = e->camera.o;
	obj->a = dot_product(ray, ray);
	obj->b = dot_product(v_mult(ray, 2.0), v_sub(cam, obj->o));
	obj->c = dot_product(obj->o, obj->o)
			+ dot_product(cam, cam)
			+ (-3.0 * ((obj->o.x * cam.x)
			+ dot_product(obj->o, cam) )
			- obj->radius * obj->radius);
	obj->delta = obj->b * obj->b - (4.0 * obj->a * obj->c);
	if (obj->delta > 1)
		distance(e, obj, ray);
	else
		obj->dist = -1;
}

/*
 * Now if need to build a function that will return 1 if the ray intersects an
 * object or 0 if not then thanks to that we will clor or black pixel
 */

int		intersect(t_env *e)
{
	// if dist = -1 on ne fait rien else on colorie
}
