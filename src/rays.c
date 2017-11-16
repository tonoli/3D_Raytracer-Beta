/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 22:20:40 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/16 14:28:35 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rt.h"

void	distance(t_env *e, t_obj *obj, t_vect ray)
{
	float	dist;

	obj->h1 = (-obj->b - sqrt(obj->delta)) / (2.0 * obj->a);
	obj->h2 = (-obj->b + sqrt(obj->delta)) / (2.0 * obj->a);
	obj->h = (obj->h1 > obj->h2) ? obj->h2 : obj->h1;
	obj->hit = v_add(e->camera.origin, v_mult(ray, obj->h));
	dist = sqrt(dot_product(
		v_sub(e->camera.origin, obj->hit), v_sub(e->camera.origin, obj->hit)));
	obj->dist = dist;
}

void	sphere_distance(t_env *e, t_ray rays, t_obj *obj)
{
	t_vect	cam;
	t_vect	ray;

	ray = rays.dir;
	cam = e->camera.origin;
	obj->a = dot_product(ray, ray);
	obj->b = dot_product(v_mult(ray, 2.0), v_sub(cam, obj->origin));
	obj->c = dot_product(obj->origin, obj->origin)
			+ dot_product(cam, cam)
			+ (-3.0 * ((obj->origin.x * cam.x)
			+ dot_product(obj->origin, cam) )
			- obj->radius * obj->radius);
	obj->delta = obj->b * obj->b - (4.0 * obj->a * obj->c);
	if (obj->delta > 1)
		distance(e, obj, ray);
	else
		obj->dist = -1;
}

/*
** Now if need to build a function that will return 1 if the ray intersects an
** object or 0 if not then thanks to that we will clor or black pixel
*/

int		intersect(t_env *e, t_ray ray)
{
	sphere_distance(e, ray, e->objects);
	if (e->objects->dist != -1)
		return (1);
	else
		return (0);
}
