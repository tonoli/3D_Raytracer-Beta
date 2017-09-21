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

int		scene_selector(t_env *e)
{
	char *scene;

	scene = e->scene;
	if (ft_strcmp(scene, '1') || ft_strcmp(scene, '2') || ft_strcmp(scene,'3'))
		return (1);
	else if (scene[0] == '1')
	{
		new_obj(sphere, 42);
		v_null(obj->origin);
		v_null(obj->dir);

	}
	else if (scene[0] == '2')
	{
		// render sphere + cone + cilindre
	}
	else
	{
		// render pilers lumieres multiples complexte
	}
	return (0);
}
