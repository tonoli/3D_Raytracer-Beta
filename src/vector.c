/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 11:25:07 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/28 02:12:04 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		dot_product(t_vect a, t_vect b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vect		v_add(t_vect a, t_vect b)
{
	t_vect v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

t_vect		v_sub(t_vect a, t_vect b)
{
	t_vect	v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}

t_vect		v_mult(t_vect a, float t)
{
	t_vect	v;

	v.x = t * a.x;
	v.y = t * a.y;
	v.z = t * a.z;
	return (v);
}

t_vect		v_power(t_vect a, int n)
{
	t_vect	v;

	v.x = pow(a.x, n);
	v.y = pow(a.y, n);
	v.z = pow(a.z, n);
	return (v);
}

t_vect	v_factor(t_vect a, double factor, t_vect b)
{
	t_vect v;

	v.x = a.x + (factor * b.x);
	v.y = a.y + (factor * b.y);
	v.z = a.z + (factor * b.z);
	return (v);
}

t_vect v_null(void)
{
	t_vect a;

	a.x = 0;
	a.y = 0;
	a.z = 0;
	return (a);
}

double	v_magnitude(t_vect v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

t_vect	vector_normalize(t_vect a)
{
	t_vect v;

	v = v_mult(a, 1 / (v_magnitude(a)));
	return (v);
}
