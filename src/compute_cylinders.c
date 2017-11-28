#include "rt.h"

void	cyl_intersection_distance(t_env *e, t_obj *obj, t_vector v)
{
	t_vector	camera;
	double		distance;

	camera = e->camera.ori;
	obj->t1 = (-obj->b - sqrt(obj->d)) / (2.0 * obj->a);
	obj->t2 = (-obj->b + sqrt(obj->d)) / (2.0 * obj->a);
	obj->t = MIN(obj->t1, obj->t2);
	obj->cross.x = camera.x + obj->t * v.x;
	obj->cross.y = camera.y + obj->t * v.y;
	obj->cross.z = camera.z + obj->t * v.z;
	distance = sqrt(  pow(camera.x - obj->cross.x, 2.0)
					+ pow(camera.y - obj->cross.y, 2.0)
					+ pow(camera.z - obj->cross.z, 2.0));
	obj->cross_distance = distance;
}

void	cyl_distance(t_env *e, t_vector ray, t_obj *obj)
{
	t_vector		camera;
	t_vector	v;

	camera = e->camera.ori;



	v = ray;
	obj->a = pow(v.x, 2.0) + pow(v.z, 2.0);
	obj->b = (2 * v.x * (camera.x - obj->ori.x)) + (2 * v.z * (camera.z - obj->ori.z));
	obj->c = pow(camera.x - obj->ori.x, 2) + pow(camera.z - obj->ori.z, 2) - obj->radius;
	obj->d = pow(obj->b, 2.0) - (4.0 * obj->a * obj->c);
	if (obj->d > 1)
		cyl_intersection_distance(e, obj, v);
	else
		obj->cross_distance = -1;
}
