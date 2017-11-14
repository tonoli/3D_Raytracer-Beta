/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 23:27:55 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/05 21:36:12 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rt.h"

static void init_val(t_env *e)
{
	e->image_w = 0;
	e->image_h = 0;
}

void		init(t_env *e)
{
	if(!(scene_selector(e)))
		ft_error(SCENE);
	e->mlx = mlx_init();
	init_val(e);
	init_objects(e);
	e->win = mlx_new_win(e->mlx, -1, -1, WIN_W, WIN_H, WIN_NAME);
	e->img = mlx_new_img(e->mlx, WIN_W, WIN_H, BLACK);
	e->img_data = (int *)mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
}

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

void	create_objects(t_env *e)
{
	t_obj		*obj;

	e->camera.origin.x = 0;
	e->camera.origin.y = 0;
	e->camera.origin.z = -300;
	e->camera.dir.x = 0;
	e->camera.dir.y = 0;
	e->camera.dir.z = 1;

	obj = new_obj(OBJ_SPHERE);
	obj->color = RED;
	obj->origin.x = 0;
	obj->origin.y = 0;
	obj->origin.z = 0;
	obj->radius = 21;
	obj->radius *= obj->radius;
	obj_push_back(&e->objects, obj);

	obj = new_obj(OBJ_SPHERE);
	obj->color = WHITE;
	obj->ori.x = 0;
	obj->ori.y = 42;
	obj->ori.z = 0.25;
	obj->radius = 10;
	obj->radius *= obj->radius;
	obj_push_back(&e->objects, obj);

}
