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

int		get_next_matrix(int **map, char **temp, int x, int y)
{
	
}

int		fileformat(int fd, int **map)
{
	char	**temp;
	char	*gnl;
	int		tempint;

	while (get_next_line(fd, &gnl) == 1)
	{
		temp = ft_strsplit(gnl, ' ');
		ft_strdel(&gnl);
		if (get_next_matrix(map, temp, 0, 0) == 0)
			return (0);
	}
	return (1);
}