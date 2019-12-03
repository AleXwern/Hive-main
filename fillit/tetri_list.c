/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:40:24 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/20 13:06:14 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		check_xy(t_tetri *blist, int x, int y)
{
	while (y < 4 && blist->block[y][x] != '#')
	{
		x = 0;
		while (x < 4 && blist->block[y][x] != '#')
		{
			x++;
		}
		if (blist->block[y][x] == '#')
			break ;
		y++;
		x = 0;
	}
	blist->y = y;
	blist->x = x;
}

static int		allocate_last_block(t_tetri **blist)
{
	int d;

	d = -1;
	while (++d < 4)
		(*blist)->block[d] = ft_memset(ft_strnew(4), '.', 4);
	(*blist)->block[d] = NULL;
	free_memory((*blist)->block);
	free(*blist);
	*blist = NULL;
	return (1);
}

int				comp_blocks(t_tetri **blist, int fd, int i, char a)
{
	char	*temp;

	*blist = malloc(sizeof(t_tetri));
	(*blist)->block = (char**)malloc(sizeof(char*) * 4 + 1);
	while (i < 4)
	{
		if (get_next_line(fd, &temp) == 0)
			return (allocate_last_block(blist));
		(*blist)->block[i] = ft_strdup(temp);
		ft_strdel(&temp);
		i++;
	}
	(*blist)->block[i] = NULL;
	(*blist)->alpha = a;
	check_xy(*blist, 0, 0);
	get_next_line(fd, &temp);
	free(temp);
	comp_blocks(&(*blist)->next, fd, 0, a + 1);
	return (0);
}
