
#include "../inc/rt.h"

void	fill_img(t_env *e)
{
	e->x = -1;
	while (++e->x < WIN_W)
	{
    e->y = -1;
    while (++e->y < WIN_H)
    {
    color = compute_objects(e, ray);
    e->img_data[e->y][e->x] = color;
    }
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
