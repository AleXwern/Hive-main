/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:17:38 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/26 19:10:28 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				*relative_offset(t_tetri *blist, int y, int x, int *i)
{
	int		*offset;
	int		count;

	count = 0;
	if (*i == 3 || *i == 0)
		*i = 0;
	offset = (int*)malloc(sizeof(int) * 4);
	offset[3] = x + 1;
	offset[2] = y;
	while (blist->block[offset[2]])
	{
		if (blist->block[offset[2]][offset[3]] == '\0')
		{
			offset[3] = 0;
			offset[2]++;
		}
		if (blist->block[offset[2]][offset[3]] == '#')
		{
			if (count == *i)
				return (set_offset(offset, x, y, i));
			count++;
		}
		offset[3]++;
	}
	return (offset);
}

static int		set_piece(char **map, t_tetri *blist, int x, int y)
{
	int			*offset;
	int			track;
	static int	i;

	track = 1;
	map[y][x] = blist->alpha;
	while (track < 4)
	{
		offset = relative_offset(blist, blist->y, blist->x, &i);
		map[y + offset[0]][x + offset[1]] = blist->alpha;
		free(offset);
		track++;
	}
	return (1);
}

static void		backtrack(char **map, char c)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}

int				block_check(char **map, t_tetri *blist)
{
	int x;
	int y;

	if (blist == NULL)
		return (1);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (check_fit(map, blist, x, y))
			{
				set_piece(map, blist, x, y);
				if (block_check(map, blist->next))
					return (1);
				else
					backtrack(map, blist->alpha);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int				place_blocks(t_tetri *blocks)
{
	char	**map;
	int		length;

	if (count_tetri(blocks) > 26)
	{
		free_list(&blocks);
		ft_putendl("error");
		return (-1);
	}
	length = smallest_square((count_tetri(blocks) * 4));
	map = allocate_map(length);
	while (!block_check(map, blocks))
	{
		free_memory(map);
		length++;
		map = allocate_map(length);
	}
	print_map(map);
	free_memory(map);
	free_list(&blocks);
	return (1);
}
