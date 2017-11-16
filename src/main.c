/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:17:50 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/16 14:57:40 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rt.h"

int		main(int ac, char **av)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (ft_error(MALLOC));
	if (ac != 2)
		return (ft_error(ARGV));
	e->scene = av[1];
	init(e);
	printf("Int ok\n");
	draw(e);
	printf("draw\n");
	mlx_hook(e->win, 6, 0, mouse_move, e);
	mlx_hook(e->win, 17, 0, kill_program, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
}
