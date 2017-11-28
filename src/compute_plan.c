/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_plan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:11:48 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/28 02:11:17 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	plane_intersection_distance(t_env *e, t_obj *obj, t_vector v)
{
	t_vector camera;
	double	distance;

	camera = e->camera.ori;
	obj->cross.x = camera.x + (obj->t * v.x);
	obj->cross.y = camera.y + (obj->t * v.y);
	obj->cross.z = camera.z + (obj->t * v.z);
	distance = sqrt(  pow(camera.x - obj->cross.x, 2.0)
					+ pow(camera.y - obj->cross.y, 2.0)
					+ pow(camera.z - obj->cross.z, 2.0));
	obj->cross_distance = distance;
}

void	plane_distance(t_env *e, t_vector ray, t_obj *obj)
{
	t_vector		camera;
	t_vector	v;

	camera = e->camera.ori;
	v = ray;
	obj->a = (obj->dir.x * (obj->ori.x - camera.x))
	+ (obj->dir.y * (obj->ori.y - camera.y))
	+ (obj->dir.z * (obj->ori.z - camera.z));
	obj->b = (obj->dir.x * v.x) + (obj->dir.y * v.y) + (obj->dir.z * v.z);
	if (obj->b != 0 && obj->b != 0.000001)
		obj->t = obj->a / obj->b;
	else
		obj->t = -1;
	if (obj->t >= 0)
		plane_intersection_distance(e, obj, v);
	else
		obj->cross_distance = 0;
}
