/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:18:31 by itonoli-          #+#    #+#             */
/*   Updated: 2017/06/26 23:53:18 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../libft/inc/libft.h"
# include "../minilibx/includes/mlx.h"
# include "macros.h"

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	void	*ptr_img;
	int		*img_data;
	void	*ptr_menu;
	int		*menu_data;
	int		image_w;
	int		image_h;

	int		bpp;
	int		size_line;
	int		endian;
}					t_env;

void	ft_error(int i);
void	init(t_env *e);

#endif
