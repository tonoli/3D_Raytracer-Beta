/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 22:27:43 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/05 21:35:39 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/*
** MLX window
*/

# define WIN_NAME	"RTv1 itonoli"
# define WIN_W		1280
# define WIN_H		720
# define MENU_W		60

/*
** Keyboard keys
*/

# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define PLUS		69
# define MOINS		78
# define PAGEUP		116
# define PAGEDOWN	121
# define SPACE		49
# define ESC_KEY	53
# define W			13
# define S			1
# define A			0
# define D			2
# define Z			6
# define X			7
# define C			8
# define V			9
# define R			15

/*
** Errors
*/

# define ARGV 0
# define MALLOC 1
# define INPUT 2
# define SCENE 3

/*
** Types of objects
*/

# define SPHERE 1
# define CONE 2
# define CYLINDRE 3
# define PLAN 4
# define LUMIERE 5

/*
** Colors
*/

# define LIGHTBLUE	0x4FC3F7
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x4CAF50
# define ORANGE		0xFB8C00
# define GREY		0x757575
# define BROWN		0x795548
# define BLACK		0x000000

#endif
