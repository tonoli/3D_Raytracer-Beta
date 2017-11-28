/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawgui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:09:16 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/28 02:11:32 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			new_box(t_env *e, int size, int height)
{
	int	bpp;
	int	size_line;
	int	endian;

	e->gui = mlx_new_img(e->mlx, size, height, GREEN);
	e->gui_data = (int*)mlx_get_data_addr(e->gui, &bpp,
		&size_line, &endian);
  createbox(e, size, height);
}

void draw_gui(t_env *e)
{
  new_box(e, 100, 200);
	mlx_put_img_to_win(e->mlx, e->win, e->gui, 100, 100);
}
