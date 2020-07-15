/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:13:55 by anystrom          #+#    #+#             */
/*   Updated: 2020/07/06 14:16:38 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	validate_map(t_wolf *wlf, int i, int a)
{
	while (++a < wlf->mxflr)
	{
		i = -1;
		while (++i < wlf->width)
		{
			if (wlf->map[a][0][i] != 2)
				error_out(FIL_ERROR, wlf, 0);
			if (wlf->map[a][wlf->height - 1][i] != 2)
				error_out(FIL_ERROR, wlf, 0);
		}
		i = -1;
		while (++i < wlf->height)
		{
			if (wlf->map[a][i][0] != 2)
				error_out(FIL_ERROR, wlf, 0);
			if (wlf->map[a][i][wlf->width - 1] != 2)
				error_out(FIL_ERROR, wlf, 0);
		}
	}
}

int		templen(char **temp)
{
	int		i;

	i = 0;
	while (temp[i])
		i++;
	return (i);
}

int		get_next_matrix(t_wolf *wlf, char **temp, int x, int y)
{
	int		wid;

	wid = templen(temp);
	if (wlf->width == -1)
		wlf->width = wid;
	if (wid < 4 || wid >= 35 || wlf->width != wid)
		return (0);
	if (!(wlf->map[wlf->flr][y] = (int*)malloc(sizeof(int) * wid)))
		error_out(MEM_ERROR, wlf, y);
	while (temp[x])
	{
		wlf->map[wlf->flr][y][x] = ft_atoi(temp[x]);
		if (wlf->map[wlf->flr][y][x] < 1 || wlf->map[wlf->flr][y][x] > 6)
			return (0);
		x++;
	}
	return (1);
}

void	fileformat(int fd, t_wolf *wlf, int y)
{
	char	**temp;
	char	*gnl;

	while (get_next_line(fd, &gnl) == 1)
	{
		if (y >= 35)
			error_out(FIL_ERROR, wlf, y);
		temp = ft_strsplit(gnl, ' ');
		free(gnl);
		if (get_next_matrix(wlf, temp, 0, y) == 0)
		{
			free_memory(temp);
			error_out(FIL_ERROR, wlf, y);
		}
		y++;
		free_memory(temp);
	}
	if (wlf->height == -1)
		wlf->height = y;
	if (y != wlf->height || wlf->height < 4)
		error_out(FIL_ERROR, wlf, y);
}

void	comp_map(t_wolf *wlf, char *av)
{
	char	*flrfl;
	int		fd;

	wlf->height = -1;
	wlf->width = -1;
	if (!(wlf->map = (int***)malloc(sizeof(int**) * wlf->mxflr)))
		error_out(MEM_ERROR, wlf, 0);
	while (wlf->flr < wlf->mxflr)
	{
		if (wlf->flr >= wlf->mxflr)
			return ;
		if (!(wlf->map[wlf->flr] = (int**)malloc(sizeof(int*) * 35)))
			error_out(MEM_ERROR, wlf, 0);
		wlf->flr += 49;
		flrfl = ft_quadjoin(av, "/", (char*)&(wlf->flr), "");
		ft_putendl(flrfl);
		fd = open(flrfl, O_RDONLY);
		free(flrfl);
		if (fd == -1)
			error_out(FLR_ERROR, wlf, 0);
		wlf->flr -= 49;
		fileformat(fd, wlf, 0);
		wlf->flr++;
	}
	validate_map(wlf, -1, -1);
}
