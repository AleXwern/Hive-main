/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JessicaNystrom <JessicaNystrom@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:24:47 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/13 12:19:48 by JessicaNyst      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUE_H
# define VALUE_H

/*
** Error messages.
*/
# define G_ERROR	"General error happened. Exiting program."
# define B_ARG		"Error: Bad argument."
# define USAGE		"Usage:	./wolf3d [tileset, 1-6] [FOLDER name, ex. map/]"
# define MEM_ERROR	"Not enough memory to allocate space for ./wolf3d."
# define T_ERROR	"There was a threading problem."
# define OOPS		"This should never be shown. Everyone panic!"
# define FINE		"Successfully exiting program."
# define WIN_ERROR	"Could not create a window."
# define IMG_ERROR	"Could not create a image."
# define MLX_ERROR	"Could not cleate MLX pointer."
# define GFX_ERROR	"GFX doesn't exist. Put it back!"
# define FLR_ERROR	"Not enough floors in given folder."
# define STR_ERROR	"Stairs don't lead anywhere. Dest need to have same XY pos"
# define FIL_ERROR	"File incorrectly formated."

/*
** Window size.
*/
# define WINX		1080
# define WINY		720
/*

** Tagged keys.
# define ESC		53
# define KEY_R		15
# define KEY_C		8
# define KEY_ONE	18
# define KEY_TWO	19
# define KEY_TRE	20
# define KEY_FOU	21
# define SPACE		49
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define SCR_UPH	4
# define SCR_DOWN	5
# define NUM_PLU	69
# define NUM_MIN	78
# define SLASH		75
# define STAR		67
*/
# define ESC		53
# define KEY_R		15
# define KEY_C		8
# define KEY_ONE	18
# define KEY_TWO	19
# define KEY_TRE	20
# define KEY_FOU	21
# define SPACE		49
# define UP			65362
# define DOWN		65364
# define LEFT		65361
# define RIGHT		65363
# define SCR_UPH	4
# define SCR_DOWN	5
# define NUM_PLU	69
# define NUM_MIN	78
# define SLASH		75
# define STAR		67
#endif
