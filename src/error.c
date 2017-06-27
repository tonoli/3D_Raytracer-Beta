/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 23:21:45 by itonoli-          #+#    #+#             */
/*   Updated: 2017/06/27 00:00:59 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rt.h"

int		kill_program(void)
{
	exit(0);
	return (0);
}

void	ft_error(int i)
{
	if (i == 0)
		ft_puterror("Usage : ./rtv1 <scene>");
	else if (i == 1)
		ft_puterror("error: Dynamic memory allocation failed.");
	else if (i == 2)
		ft_puterror("error: The imput file is not valid.");
}
