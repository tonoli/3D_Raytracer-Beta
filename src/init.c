/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 23:27:55 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/16 15:42:42 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rt.h"

void		init(t_env *e)
{
	if(!(scene_selector(e)))
		ft_error(SCENE);
	e->mlx = mlx_init();
	e->win = mlx_new_win(e->mlx, -1, -1, WIN_W, WIN_H, WIN_NAME);
	e->img = mlx_new_img(e->mlx, WIN_W, WIN_H, BLACK);
	e->img_data = (int *)mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
}
