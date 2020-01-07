/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:12:21 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/07 13:43:32 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>
# include <mlx.h>
# include <fcntl.h>

/*
** Struct for complex number presentation.
** r is real part.
** i is imaginary part.
*/
typedef struct	s_complex
{
	int			r;
	int			i;
}				t_complex;

/*
** Image handling
** void *img = image pointer
** int sizel = 
** int bpp = bytes per pixel
** int endn = big or small endian
*/
typedef struct	s_image
{
	void		*img;
	int			sizel;
	int			bpp;
	int			endn;
}				t_image;

/*
** General toolbox for handling information.
** void *mlx = generic mlx pointer.
** void *win = generil mlx window pointer.
** int fractol = id of fractol type. -1 equals error.
*/
typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	int			fractol;
}				t_fractol;

#endif
