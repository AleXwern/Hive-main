/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:13:55 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/01 15:20:10 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "value.h"
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# define WINX	1920
# define WINY	1080

/*
**	Matrix structure to hold XYZ coords and location of next 2 pointers.
*/

typedef struct	s_marix
{
	int			y;
	int			x;
	int			z;
	int			up;
	int			left;
	int			sx;
	int			sy;
}				t_matrix;

/*
**	General structure that holds everything.
*/

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	double		sinrot;
	double		fltrot;
	double		deltax;
	double		deltay;
	int			rlsin;
	int			rlflt;
	int			mult;
	int			pad;
	int			center;
	int			posx;
	int			posy;
	int			width;
	int			height;
	t_matrix	*matrix;
}				t_fdf;

int		fileformat(int fd, t_fdf *fdf);
int		key_main(int key, t_fdf *fdf);
int		mouse_main(int key, int x, int y, t_fdf *fdf);

void	draw_image(t_fdf *fdf, int c);
void	error_out(char *msg, t_fdf *fdf);
void	fdf_main(t_fdf *fdf, int fd, char *av);

#endif