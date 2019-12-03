/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:17:38 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/26 18:29:38 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	reset_ints(int *coll, int *count, int *index)
{
	*count = 0;
	*coll = 0;
	*index = 0;
}

int		count_tetri(t_tetri *blocks)
{
	int		i;

	i = 0;
	while (blocks)
	{
		blocks = blocks->next;
		i++;
	}
	return (i);
}

int		smallest_square(int i)
{
	int		check;

	check = 2;
	while (check * check < i)
		check++;
	return (check);
}

char	**allocate_map(int length)
{
	int		i;
	char	**arr;

	i = -1;
	if (!(arr = (char**)malloc(sizeof(char*) * length + 1)))
		return (NULL);
	while (++i < length)
		arr[i] = ft_memset(ft_strnew(length), '.', length);
	arr[i] = NULL;
	return (arr);
}

int		check_fit(char **map, t_tetri *blist, int x, int y)
{
	int			track;
	int			tru;
	int			*offset;
	static int	i;

	track = 0;
	tru = 1;
	if (y >= (int)ft_strlen(map[0]) || map[y][x] != '.')
		return (0);
	while (++track < 4)
	{
		offset = relative_offset(blist, blist->y, blist->x, &i);
		if (offset[0] + y >= (int)ft_strlen(map[y]))
			break ;
		if (map[y + offset[0]][x + offset[1]] != '.')
			break ;
		if (map[y + offset[0]][x + offset[1]] == '.')
			tru++;
		free(offset);
	}
	if (track != 4)
		free(offset);
	if (tru != 4)
		i = 0;
	return (tru == 4);
}
