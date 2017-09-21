/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 23:53:00 by itonoli-          #+#    #+#             */
/*   Updated: 2017/09/15 12:45:24 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rt.h"

void	fill_img(t_env *e)
{
	t_ray	ray;
	float	ratio;

	ratio = WIN_W / WIN_H;
	e->x = -1;
	while (++e->x < WIN_W)
	{
		e->y = -1;
		while (++e->y < WIN_H)
		{
			t_vect	v;

			v.x = ((2 * ((e->x + 0.5) / WIN_W)) - 1) * ratio * (tan((60 / 2) * M_PI / 180));
			v.y = ((1 - (2 * ((e->y + 0.5) / WIN_H))) * tan((60 / 2) * M_PI / 180));
			v.z = 1;

			ray.origin = e->camera.origin;
			ray.dir = v;
			if (intersect(e, ray))
				e->img_data[e->y * WIN_W + e->x] = WHITE;
		}
	}
	mlx_put_img_to_win(e->mlx, e->win, e->img, 0, 0);
}
