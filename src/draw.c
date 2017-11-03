/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 23:53:00 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/03 19:07:39 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rt.h"

int	get_color(int color, double coef)
{
	int r;
	int g;
	int b;

	r = ((color >> 16) & 0xFF) * (double)coef;
	g = ((color >> 8) & 0xFF) * (double)coef;
	b = (color & 0xFF) * (double)coef;

	return ((r << 16) + (g << 8) + b);
}

void	fill_img(t_env *e)
{
	int color;
	double ratio;
	t_vect v;

	e->x = -1;
	while (++e->x < WIN_W)
	{
    e->y = -1;
    while (++e->y < WIN_H)
    {
			ratio = WIN_W / WIN_H;
			v.x = ((2 * ((i + 0.5) / F_WIDTH)) - 1) * ratio * (tan((60 / 2) * M_PI / 180));
			v.y = ((1 - (2 * ((j + 0.5) / F_HEIGHT))) * tan((60 / 2) * M_PI / 180));
			v.z = 1;
			ray.dir = v;
			ray.ori = e->camera.ori;
			color = compute_objects(e, ray);
      e->img_data[e->y][e->x] = color;
    }
	}
	mlx_put_img_to_win(e->mlx, e->win, e->img, 0, 0);
}
