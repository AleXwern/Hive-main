/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:24:47 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/24 15:57:37 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUE_H
# define VALUE_H

/*
** Error messages.
*/
# define G_ERROR	"General error happened. Exiting program."
# define B_ARG		"Error: Bad argument."
# define USAGE		"Usage:	./fractol mandelbrot/julia/bship/psecorn"
# define MEM_ERROR	"Not enough memory to allocate space for ./fractol."
# define T_ERROR	"There was a threading problem."
# define OOPS		"This should never be shown. Everyone panic!"
# define FINE		"Successfully exiting program."
# define WIN_ERROR	"Could not create a window."
# define IMG_ERROR	"Could not create a image."
# define MLX_ERROR	"Could not cleate MLX pointer."

/*
** Window size.
*/
# define WINX		1080
# define WINY		720

/*
** Tagged keys.
*/
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

/*
** Help data
*/
# define DATA		0x13D9EC
# define HL			0xff3333
# define HLP		"HELP"
# define HLP_A		"ESC    = exit"
# define HLP_B		"R      = reset"
# define HLP_C		"SPACE  = (un)anchor julia"
# define HLP_D		"D-PAD  = move"
# define HLP_E		"H      = open/close help"
# define HLP_F		"1234   = change factal"
# define HLP_G		"C      = change color"
# define HLP_H		"SCROLL = zoom in/out"
# define HLP_I		"/*     = add/remove threads"
# define HLP_J		"+-     = change iteration"
# define DATA_F		"Julia is fixed"
# define DATA_O		"Julia is not fixed"

#endif
