/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:03:33 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/16 15:58:29 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rt.h"

void createbox(t_env *e, int size, int height)
{
  int i = - 1;
  while (++i < size)
  {
    int j = - 1;
    while (++j < height)
    {
      e->gui_data[j * size + i] = BROWN;
    }
  }
}
