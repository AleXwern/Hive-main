/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chess.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:03:52 by exam              #+#    #+#             */
/*   Updated: 2020/01/28 15:49:20 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int		checkboard(int wid, char **brd, int x, int y)
{
	int		tru;

	tru = 0;
	while (y < wid)
	{
		x = 0;
		while (x < wid - 1)
		{
			if (brd[y][x] == 'P')
				tru += pawn_move(wid, brd, x, y);
			else if (brd[y][x] == 'B')
				tru += bishop_move(wid, brd, x, y);
			else if (brd[y][x] == 'R')
				tru += rook_move(wid, brd, x, y);
			else if (brd[y][x] == 'Q')
				tru += queen_move(wid, brd, x, y);
			x++;
		}
		y++;
	}
	return (tru);
}

int		lencheck(int ac, char *av)
{
	int		i;

	i = 0;
	while (av[i] != '\0')
		i++;
	if (i == ac - 1)
		return (1);
	else
		return (0);
}

int		main(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!lencheck(ac, av[i]))
		{
			write(1, "\n", 1);
			return (0);
		}
		i++;
	}
	if (ac == 1)
		write(1, "\n", 1);
	else
	{
		if (checkboard(ac, av, 0, 1))
			write(1, "Success\n", 8);
		else
			write(1, "Fail\n", 5);
	}
	return (0);
}
