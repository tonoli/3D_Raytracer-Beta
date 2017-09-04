/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 22:20:40 by itonoli-          #+#    #+#             */
/*   Updated: 2017/09/04 15:53:25 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rt.h"

int solve_quadratic(const float a, const float b, const float c, float x0, float x1)
{
	float	discr;
	float	tmp;
	float	q;

	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		x0 = -0.5 * b / a;
		x1 = -0.5 * b / a;
	}
	else
	{
		q = (b > 0) ? -0.5 * (b + sqrt(discr)) : -0.5 * (b - sqrt(discr));
		x0 = q / a;
		x1 = c / q;
	}
	if (x0 > x1)
	{
		tmp = x1;
		x1 = x0;
		x0 = x1;
	}
	return (1);
}

float	dot_product(t_vect a, t_vect b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float	cross_product(t_vect a, t_vect b)
{
	t_vect	 
	return (
}

int		intersect(t_env *e)
{
	t_vect l;

	l = e->orign - center;
	e->a =
	if (!(solveQuadratic(e->a, e->b, e->c, e->t0, e->t1)))
		return (0);


}
