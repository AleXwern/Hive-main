/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_valid_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:05:07 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/11/26 18:29:08 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_collision(char **arr, int y, int x, int i)
{
	int coll;

	coll = 0;
	if (i != 0 && arr[y - 1][x] == '#')
		coll++;
	if (i != 3 && arr[y + 1][x] == '#')
		coll++;
	if (x != 0 && arr[y][x - 1] == '#')
		coll++;
	if (x != 3 && arr[y][x + 1] == '#')
		coll++;
	return (coll);
}

static int		check_arr(char **arr, int index, int y, int count)
{
	int x;
	int coll;

	coll = 0;
	while (arr[++y])
	{
		x = -1;
		if (index == 4)
		{
			if (count != 4 || coll < 6)
				return (-1);
			reset_ints(&coll, &count, &index);
		}
		while (arr[y][++x])
			if (arr[y][x] == '#')
			{
				coll += check_collision(arr, y, x, index);
				count++;
			}
		index++;
	}
	free_memory(arr);
	if (count != 4 || coll < 6)
		return (-1);
	return (0);
}

static int		check_if_valid_tetrimino(char *str)
{
	int		index;
	char	**arr;
	int		y;
	int		count;

	count = 0;
	index = 0;
	y = -1;
	arr = ft_strsplit(str, '\n');
	free(str);
	return (check_arr(arr, index, y, count));
}

static int		check_characters(char *line, int index)
{
	while (line[index])
	{
		if (line[index] != '.' && line[index] != '#' && line[index] != '\n')
			return (-1);
		index++;
	}
	index = 0;
	if (ft_strlen(line) != 4)
	{
		free(line);
		return (-1);
	}
	free(line);
	return (0);
}

int				check_if_valid_file(const int fd, int count,
		int index, char *line)
{
	char	*str[3];

	str[0] = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		str[1] = ft_strjoin(line, "\n");
		str[2] = ft_strjoin(str[0], str[1]);
		free(str[0]);
		str[0] = str[2];
		free(str[1]);
		if (count != 4)
		{
			if (check_characters(line, index) != 0)
				return (-1);
			count++;
		}
		else
		{
			if (line[0] != '\0')
				return (-1);
			count = 0;
			free(line);
		}
	}
	return (check_if_valid_tetrimino(str[0]));
}
