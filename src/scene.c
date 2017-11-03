/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:52:23 by itonoli-          #+#    #+#             */
/*   Updated: 2017/09/08 15:04:03 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rt.h"

t_obj new_obj(int type, float radius, t_vect origin)
{
	t_obj *new;

	if (!(new = (t_obj *)malloc(sizeof(t_obj))))
		ft_error(MALLOC);
	new->type = type;
	new->radius = radius;
	new->origin = origin;
	new->next = NULL;
	return (*new);
}

/*
** Definition of scenes and where you can change values to test
*/

void scene1(t_env *e)
{

}

void scene2(t_env *e)
{

}

void scene3(t_env *e)
{

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
		return(1);
	return (0);
}
