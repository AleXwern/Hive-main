/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:13:55 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/04 16:01:17 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

int		searchid(t_wolf *wolf, int x, int y)
{
	int		i;

	i = 0;
	while (i < fdf->mallocht * fdf->width)
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
		if (ft_isdigit(temp[t]) || (temp[t] == '-' && t == 0))
			t++;
		else
			return (0);
	}
	fdf->matrix[mtx].x = x;
	fdf->matrix[mtx].y = y;
	fdf->matrix[mtx].z = ft_atoi(temp);
	if (fdf->matrix[mtx].z > fdf->top)
		fdf->top = fdf->matrix[mtx].z;
	fdf->matrix[mtx].left = -1;
	fdf->matrix[mtx].up = -1;
	fdf->matrix[mtx].top = -1;
	if (x > 0)
		fdf->matrix[mtx].left = searchid(fdf, x - 1, y);
	if (y > 0)
		fdf->matrix[mtx].up = searchid(fdf, x, y - 1);
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

int		get_next_matrix(t_wolf *wolf, char **temp, int x, int y)
{
	if (templen(temp) != 25)
		return (0);
	while (temp[x] && x < 25)
	{
		if ()
			return (0);
		x++;
	}
	return (1);
}

int		fileformat(int fd, t_wolf *wolf)
{
	char	**temp;
	char	*gnl;
	int		y;

	y = 0;
	while (get_next_line(fd, &gnl) == 1)
	{
		temp = ft_strsplit(gnl, ' ');
		free(gnl);
		if (get_next_matrix(wolf, temp, 0, y) == 0)
		{
			free_memory(temp);
			error_out(FIL_ERROR, wolf);
		}
		y++;
		free_memory(temp);
	}
	return (1);
}

void	comp_gfx(t_wolf *wolf)
{

}