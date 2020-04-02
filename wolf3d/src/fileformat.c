/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:13:55 by anystrom          #+#    #+#             */
/*   Updated: 2020/04/01 13:18:04 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

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
		wolf->map[wolf->flr][y][x] = ft_atoi(temp[x]);
		if (wolf->map[wolf->flr][y][x] == 0)
			return (0);
		x++;
	}
	return (1);
}

void	fileformat(int fd, t_wolf *wolf)
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
	if (y != 25)
		error_out(FIL_ERROR, wolf);
	wolf->flr++;
}

void	comp_map(t_wolf *wolf, char *av)
{
	char	*flrfl;
	int		fd;

	if (wolf->flr > wolf->mxflr)
		return ;
	wolf->flr += 49;
	flrfl = ft_strjoin(av, (char*)&(wolf->flr));
	ft_putendl(flrfl);
	fd = open(flrfl, O_RDONLY);
	free(flrfl);
	if (fd == -1)
		error_out(FLR_ERROR, wolf);
	wolf->flr -= 49;
	fileformat(fd, wolf);
}