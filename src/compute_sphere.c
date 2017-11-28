/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:11:48 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/28 02:11:22 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sphere_intersection_distance(t_env *e, t_obj *obj, t_ray ray)
{
	double		distance;

	obj->h1 = (-obj->b - sqrt(obj->d)) / (2.0 * obj->a);
	obj->h2 = (-obj->b + sqrt(obj->d)) / (2.0 * obj->a);
	if (obj->h1 > 0.000001)
		obj->h = obj->h1;
	else if (obj->h2 > 0.000001)
		obj->h = obj->h2;
	else
	{
		obj->dist = -1;
		return ;
	}
	obj->cross = vector_factor(ray.ori, obj->t, ray.dir);
	distance = vector_magnitude(vector_sub(ray.ori, obj->cross));
	obj->dist = distance;
}

void	sphere_distance(t_env *e, t_obj *obj, t_ray ray)
{
	t_vector	v;

	v = vector_sub(ray.ori, obj->ori);
	obj->a = vector_dot(ray.dir, ray.dir);
	obj->b = 2.0 * vector_dot(ray.dir, v);
	obj->c = vector_dot(v, v) - obj->radius;
	obj->d = obj->b * obj->b - (4.0 * obj->a * obj->c);
	if (obj->d > 0)
		sphere_intersection_distance(e, obj, ray);
	else
		obj->cross_distance = -1;
}

// int compute(t_env *e, t_ray ray)
// {
//
// }
