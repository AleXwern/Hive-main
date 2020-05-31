/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:13:55 by anystrom          #+#    #+#             */
/*   Updated: 2020/05/25 14:44:54 by AleXwern         ###   ########.fr       */
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
	int		wid;

	wid = templen(temp);
	if (wolf->width != -1)
		wolf->width = wid;
	if (wid < 4 || wid >= 35 || wolf->width != wid)
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

void	fileformat(int fd, t_wolf *wolf, int y)
{
	char	**temp;
	char	*gnl;

	while (get_next_line(fd, &gnl) == 1)
	{
		if (y >= 35)
			error_out(FIL_ERROR, wolf);
		temp = ft_strsplit(gnl, ' ');
		free(gnl);
		if (get_next_matrix(wolf, temp, 0, wolf->height) == 0)
		{
			free_memory(temp);
			error_out(FIL_ERROR, wolf);
		}
		y++;
		free_memory(temp);
	}
	if (wolf->height != -1)
		wolf->height = y;
	if (y != wolf->height || wolf->height < 4)
		error_out(FIL_ERROR, wolf);
}

void	comp_map(t_wolf *wolf, char *av)
{
	char	*flrfl;
	int		fd;

	wolf->height = -1;
	wolf->width = -1;
	while (wolf->flr < wolf->mxflr)
	{
		if (wolf->flr > wolf->mxflr)
			return ;
		//wolf->flr += 49;
		flrfl = ft_strjoin(av, (char*)&(wolf->flr + 49));
		ft_putendl(flrfl);
		fd = open(flrfl, O_RDONLY);
		free(flrfl);
		if (fd == -1)
			error_out(FLR_ERROR, wolf);
		//wolf->flr -= 49;
		fileformat(fd, wolf, 0);
		wolf->flr++;
	}
}