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
	//printf("ID\n");
	while (i < fdf->height * fdf->width)
	{
		if (fdf->matrix[i].x == x && fdf->matrix[i].y == y)
			return (i);
		i++;
	}
	//printf("ID exit\n");
	return (-1);
}

int		addpoint(t_fdf *fdf, int x, int y, char *temp)
{
	static int	mtx;
	int			t;

	t = 0;
	printf("addpoint\n");
	while (temp[t])
	{
		if (ft_isdigit(temp[t]) || (temp[t] == '-' && t == 0))
			t++;
		else
			return (0);
		ft_putendl("Henlo");
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
	ft_putendl("addpoint exit\n");
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
	static int	o;

	//printf("GNL\n");
	if (y == 0 && x == 0)
		fdf->width = templen(temp);
	if (templen(temp) != fdf->width /*&& o != fdf->height - 1*/)
		return (0);
	if (!fdf->matrix)
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
	//printf("GNL exit\n");
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
		ft_strdel(temp);
	}
	return (1);
}