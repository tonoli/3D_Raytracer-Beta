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

void	distance(t_env *e, t_obj *obj, t_vect ray)
{
	float	dist;

	obj->h1 = (-obj->b - sqrt(obj->d)) / (2.0 * obj->a);
	obj->h2 = (-obj->b + sqrt(obj->d)) / (2.0 * obj->a);
	obj->h = (obj->h1 > obj->h2) ? h2 : h1;
	obj->hit = sum(e->camera.or, mult(ray, obj->h));
	distance = sqrt(dot_product(
		sub(e->camera.or, obj->hit), sub(e->camera.or, obj->hit)));
	obj->dist = dist;
}

void	sphere_distance(t_env *e, t_vect ray, t_obj *obj)
{
	t_vect	cam;

	cam = e->camera.or;
	obj->a = dot_product(ray, ray);
	obj->b = dot_product(mult(ray, 2.0), sub(cam, obj->or));
	obj->c = dot_product(obj->or, obj->or)
			+ dot_product(cam, cam)
			+ (-3.0 * ((obj->or.x * camera.x)
			+ dot_product(obj->or, cam) )
			- obj->radius * obj->radius;
	obj->delta = obj->b * obj->b - (4.0 * obj->a * obj->c);
	if (obj->delta > 1)
		distance(e, obj, ray);
	else
		obj->dist = -1;
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

t_vect	mult(t_vect a, float t)
{
	t_vect	v;

	v.x = t * a.x;
	v.y = t * a.y;
	v.z = t * a.z;
	return (v);
}

t_vect	power_v(t_vect a, int n)
{
	t_vect	v;

	v.x = pow(a.x, n);
	v.y = pow(a.y, n);
	v.z = pow(a.z, n);
	return (v);
}

/*
 * Now if need to build a function that will return 1 if the ray intersects an
 * object or 0 if not then thanks to that we will clor or black pixel
 */

int		intersect(t_env *e)
{
	// if dist = -1 on ne fait rien else on colorie
	
}
