/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:52:23 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/16 14:48:37 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rt.h"

// t_obj new_obj(int type, float radius, t_vect origin)
// {
// 	t_obj *new;
//
// 	if (!(new = (t_obj *)malloc(sizeof(t_obj))))
// 		ft_error(MALLOC);
// 	new->type = type;
// 	new->radius = radius;
// 	new->origin = origin;
// 	new->next = NULL;
// 	return (*new);
// }

t_obj	*new_obj(int obj_type)
{
	t_obj *new;

	new = (t_obj *)ft_memalloc(sizeof(t_obj));
	bzero(new, sizeof(t_obj));
	new->type = obj_type;
	new->next = NULL;
	return (new);
}

void	obj_push_back(t_obj **list, t_obj *cur)
{
	if (!list)
		return ;
	while (*list)
		list = &(*list)->next;
	*list = cur;
}

/*
** Definition of scenes and where you can change values to test
*/

void scene1(t_env *e)
{
	t_obj		*obj;

	e->camera.origin.x = 0;
	e->camera.origin.y = 0;
	e->camera.origin.z = -300;
	e->camera.dir.x = 0;
	e->camera.dir.y = 0;
	e->camera.dir.z = 1;

	obj = new_obj(SPHERE);
	obj->color = RED;
	obj->origin.x = 0;
	obj->origin.y = 0;
	obj->origin.z = 0;
	obj->radius = 21;
	obj->radius *= obj->radius;
	obj_push_back(&e->objects, obj);

	obj = new_obj(SPHERE);
	obj->color = WHITE;
	obj->origin.x = 0;
	obj->origin.y = 42;
	obj->origin.z = 0.25;
	obj->radius = 10;
	obj->radius *= obj->radius;
	obj_push_back(&e->objects, obj);
}

void scene2(t_env *e)
{
	if (e)
	{
		ft_putchar('2');
	}
}

void scene3(t_env *e)
{
	if (e)
	{
		ft_putchar('3');
	}
}

int		scene_selector(t_env *e)
{
	char *scene;

	scene = e->scene;
	if (ft_strcmp(scene, "1") == 0)
		scene1(e);
	else if (ft_strcmp(scene, "2") == 0)
		scene2(e);
	else if (ft_strcmp(scene, "3") == 0)
		scene3(e);
	else
		return(0);
	return (1);
}
