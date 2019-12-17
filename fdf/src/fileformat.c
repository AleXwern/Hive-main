/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:13:55 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/01 15:20:10 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_next_matrix(t_fdf *fdf, char **temp, int x, int y)
{
	t_matrix	*tempto;

	if (!fdf->width)
		fdf->width == templen(temp);
	if (!(fdf->matrix))
		if (!(fdf->matrix = (t_matrix*)malloc(sizeof(t_matrix))))
}

int		fileformat(int fd, t_fdf *fdf)
{
	char	**temp;
	char	*gnl;
	int		y;

	y = 0;
	while (get_next_line(fd, &gnl) == 1)
	{
		temp = ft_strsplit(gnl, ' ');
		ft_strdel(&gnl);
		if (get_next_matrix(fdf, temp, 0, y) == 0)
		{
			ft_strdel(gnl);
			error_out(M_ERROR, fdf);
		}
		y++;
	}
	ft_memdel(temp);
	ft_memdel(gnl);
	return (1);
}