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
# include "error.h"
# include <math.h>
# include <mlx.h>
# define WINX	1920
# define WINY	1080

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	int			**map;
}				t_fdf;

int		fileformat(int fd, int **map);

void	error_out(char *msg);
void	fdf_main(t_fdf *fdf, int fd);

#endif