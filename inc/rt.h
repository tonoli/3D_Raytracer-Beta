/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:18:31 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/16 19:05:03 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H


# include "../libft/inc/libft.h"
# include "../minilibx/includes/mlx.h"
# include "macros.h"
# include "stdio.h"

/*
** Define
*/

# define PI 3.14159265359

typedef struct		s_vect
{
	float	x;
	float	y;
	float	z;
}					t_vect;

typedef struct		s_ray
{
	t_vect dir;
	t_vect origin;
}									t_ray;

typedef struct		s_obj
{
	int						type;
	int						color;
	float					dist;
	float					h1;
	float					h2;
	float					h;
	float					a;
	float					b;
	float					c;
	float					delta;

	t_vect				origin;
	t_vect				dir;
	t_vect				hit;

	float					radius;

	struct s_obj *next;
}									t_obj;

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_data;
	void	*gui;
	int		*gui_data;
	int		image_w;
	int		image_h;
	int		x;
	int		y;

	int		bpp;
	int		size_line;
	int		endian;

	char	*scene;

	t_obj	camera;
	t_obj	*objects;
}									t_env;

float	dot_product(t_vect a, t_vect b);
t_vect	v_add(t_vect a, t_vect b);
t_vect	v_sub(t_vect a, t_vect b);
t_vect	v_power(t_vect a, int n);
t_vect	v_mult(t_vect a, float t);
t_vect	v_null(void);
t_vect	v_factor(t_vect a, double factor, t_vect b);
double	v_magnitude(t_vect v);
t_vect	vector_normalize(t_vect a);
int		intersect(t_env *e, t_ray ray);
int		scene_selector(t_env *e);
void	draw(t_env *e);
void 	draw_gui(t_env *e);
void createbox(t_env *e, int size, int height);
int		ft_error(int i);
int		kill_program(void);
void	init(t_env *e);
int		mouse_hook(int button, int x, int y, t_env *e);
int		key_hook(int key, t_env *env);
int		mouse_move(int x, int y, t_env *e);

#endif
