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

int		searchid(t_fdf *fdf, int x, int y)
{
	int		i;

	i = 0;
	while (i < fdf->height * fdf->width)
	{
		if (fdf->matrix[i].x == x && fdf->matrix[i].y == y)
			return (i);
		i++;
	}
	return (-1);
}

int		addpoint(t_fdf *fdf, int x, int y, char *temp)
{
	static int	mtx;
	int			t;
	
	t = 0;
	while (temp[t] != '\0')
	{
		if (!ft_isdigit(temp[t]))
			return (0);
		t++;
	}
	fdf->matrix[mtx].x = x;
	fdf->matrix[mtx].y = y;
	fdf->matrix[mtx].z = ft_atoi(temp);
	fdf->matrix[mtx].left = -1;
	fdf->matrix[mtx].up = -1;
	if (x > 0)
		fdf->matrix[mtx].left = searchid(fdf, x - 1, y);
	if (y > 0)
		fdf->matrix[mtx].up = searchid(fdf, x, y -1);
	mtx++;
	return (1);
}

int		templen(char **temp)
{
	int		i;

	i = 0;
	while (temp[i])
		i++;
	return (i);
}

int		get_next_matrix(t_fdf *fdf, char **temp, int x, int y)
{
	int i  = 0;
	static int o;
	printf("GNM with X%d Y%d\n", x, y);
	if (y == 0 && x == 0)
		fdf->width = templen(temp);
	if (templen(temp) != fdf->width)
		return (0);
	if (!(fdf->matrix = (t_matrix*)malloc(sizeof(t_matrix) * fdf->height
			* fdf->width)))
		return (0);
	while (temp[x])
	{
		if (!addpoint(fdf, x, y, temp[x]))
			return (0);
		x++;
	}
	o++;
	while (i < o * fdf->width)
	{
		printf("ID:%d X:%d Y:%d Z:%d Left:%d Up:%d\n", i, fdf->matrix[i].x, fdf->matrix[i].y, fdf->matrix[i].z, fdf->matrix[i].left, fdf->matrix[i].up);
		i++;
	}
	printf("----------\n");
	return (1);
}

int		fileformat(int fd, t_fdf *fdf)
{
	char	**temp;
	char	*gnl;
	int		y;

	y = 0;
	gnl = ft_strnew(1);
	while (get_next_line(fd, &gnl) == 1)
	{
		temp = ft_strsplit(gnl, ' ');
		ft_strdel(&gnl);
		if (get_next_matrix(fdf, temp, 0, y) == 0)
		{
			ft_strdel(temp);
			error_out(M_ERROR, fdf);
		}
		y++;
		ft_memdel((void**)temp);
	}
	return (1);
}