/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 23:27:55 by itonoli-          #+#    #+#             */
/*   Updated: 2017/09/04 15:40:03 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rt.h"

static void init_val(t_env *e) {
	e->image_w = 0;
	e->image_h = 0;
}

static t_vect	init_vect(float x, float y, float z)
{
	t_vect	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;

	return (vect);
}

void		init(t_env *e)
{
	e->mlx = mlx_init();
	init_val(e);
	e->win = mlx_new_win(e->mlx, -1, -1, WIN_W, WIN_H, WIN_NAME);
	e->img = mlx_new_img(e->mlx, WIN_W, WIN_H, BLACK);
	e->img_data = (int *)mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
}
