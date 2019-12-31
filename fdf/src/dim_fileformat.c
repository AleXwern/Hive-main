/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_fileformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:13:55 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/01 15:20:10 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		searchidto(t_fdf *fdf, int x, int y, int d)
{
	int		i;

	i = 0;
	while (i < fdf->mallocht * fdf->width)
	{
		if (fdf->matrix[i].x == x && fdf->matrix[i].y == y &&
				fdf->matrix[i].ht == d)
			return (i);
		i++;
	}
	return (-1);
}

void	addrelative(t_fdf *fdf, int x, int y, int mtx)
{
	if (x > 0)
		fdf->matrix[mtx].left = searchidto(fdf, x - 1, y, fdf->depth);
	if (y > 0)
		fdf->matrix[mtx].up = searchidto(fdf, x, y - 1, fdf->depth);
	if (fdf->depth > 0)
		fdf->matrix[mtx].top = searchidto(fdf, x, y, fdf->depth - 1);
}

int		addpointto(t_fdf *fdf, int x, int y, char *temp)
{
	static int	mtx;
	int			t;

	t = 0;
	while (temp[t] != '\0')
	{
		if (ft_isdigit(temp[t]) || (temp[t] == '-' && t == 0))
			t++;
		else
			return (0);
	}
	fdf->matrix[mtx].x = x;
	fdf->matrix[mtx].y = y;
	fdf->matrix[mtx].ht = fdf->depth;
	fdf->matrix[mtx].z = ft_atoi(temp);
	if (fdf->matrix[mtx].z > fdf->top)
		fdf->top = fdf->matrix[mtx].z;
	fdf->matrix[mtx].left = -1;
	fdf->matrix[mtx].up = -1;
	fdf->matrix[mtx].top = -1;
	addrelative(fdf, x, y, mtx);
	mtx++;
	return (1);
}

int		get_next_matrixto(t_fdf *fdf, char **temp, int x, int y)
{
	if (y == 0 && x == 0 && fdf->depth == 0)
		fdf->width = templen(temp);
	if (templen(temp) != fdf->width)
		return (0);
	if (!fdf->matrix)
		if (!(fdf->matrix = (t_matrix*)malloc(sizeof(t_matrix) * fdf->mallocht
				* fdf->width)))
			return (0);
	while (temp[x])
	{
		if (!addpointto(fdf, x, y, temp[x]))
			return (0);
		x++;
	}
	return (1);
}

int		dim_fileformat(int fd, t_fdf *fdf)
{
	char	**temp;
	char	*gnl;
	int		y;

	y = 0;
	while (get_next_line(fd, &gnl) == 1)
	{
		temp = ft_strsplit(gnl, ' ');
		free(gnl);
		if (temp[0][0] == 'z' && y != 0)
		{
			y = -1;
			fdf->depth++;
		}
		else if (get_next_matrixto(fdf, temp, 0, y) == 0)
		{
			free_memory(temp);
			error_out(M_ERROR, fdf);
		}
		y++;
		free_memory(temp);
	}
	return (1);
}
