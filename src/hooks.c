/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:01:51 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/28 02:11:41 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			key_hook(int key, t_env *env)
{
	if (key == ESC_KEY)
		kill_program();
	(void)env;
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	(void)button;
	(void)e;
	return (0);
}

int			mouse_move(int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	(void)e;
	return (0);
}
