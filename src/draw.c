/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 23:53:00 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/28 02:11:29 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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

void	draw(t_env *e)
{
	int color;
	//double ratio;
	// t_vect v;
	// t_ray	ray;

	e->x = -1;
	while (++e->x < WIN_W)
	{
    e->y = -1;
    while (++e->y < WIN_H)
    {
			//ratio = WIN_W / WIN_H;
			//v.x = ((2 * ((e->x + 0.5) / WIN_W)) - 1) * ratio * (tan((60 / 2) * PI / 180));
			//v.y = ((1 - (2 * ((e->y + 0.5) / WIN_H))) * tan((60 / 2) * PI / 180));
			//v.z = 1;
			//ray.dir = v;
			//ray.origin = e->camera.origin;
			//color = compute(e, ray);
			color = RED;
      e->img_data[e->y * WIN_W + e->x] = color;
    }
	}
	mlx_put_img_to_win(e->mlx, e->win, e->img, 0, 0);
	draw_gui(e);
}
