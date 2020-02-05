/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:33:43 by exam              #+#    #+#             */
/*   Updated: 2020/01/28 15:23:30 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int		ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

int		pawn_move(int wid, char **brd, int x, int y)
{
	if (y - 1 >= 0 && x - 1 >= 0)
	{
		if (brd[y - 1][x - 1] == 'K')
			return (1);
	}
	else if (y - 1 >= 0 && x + 1 < wid - 1)
		if (brd[y - 1][x + 1] == 'K')
			return (1);
	return (0);
}

int		bishop_move(int wid, char **brd, int x, int y)
{
	int		mult;
	int		px;
	int		py;

	mult = 1;
	while (mult <= 3)
	{
		py = -1;
		while (py <= 1)
		{
			px = -1;
			while (px <= 1)
			{
				if (y + (py * mult) > 0 && y + (py * mult) < wid &&
						x + (px * mult) < wid - 1 && x + (px * mult) >= 0)
					if (brd[y + (py * mult)][x + (px * mult)] == 'K')
						return (1);
				px += 2;
			}
			py += 2;
		}
		mult++;
	}
	return (0);
}

int		rook_move(int wid, char **brd, int x, int y)
{
	int		mult;
	int		px;
	int		py;

	mult = 1;
	while (mult <= 3)
	{
		py = -1;
		while (py <= 1)
		{
			px = -1 + (ft_abs(py) % 2);
			while (px <= 1)
			{
				if (y + (py * mult) > 0 && y + (py * mult) < wid &&
						x + (px * mult) < wid - 1 && x + (px * mult) >= 0)
					if (brd[y + (py * mult)][x + (px * mult)] == 'K')
						return (1);
				px += 2;
			}
			py++;
		}
		mult++;
	}
	return (0);
}

int		queen_move(int wid, char **brd, int x, int y)
{
	int		mult;
	int		px;
	int		py;

	mult = 1;
	while (mult <= 3)
	{
		py = -1;
		while (py <= 1)
		{
			px = -1;
			while (px <= 1)
			{
				if (y + (py * mult) > 0 && y + (py * mult) < wid &&
						x + (px * mult) < wid - 1 && x + (px * mult) >= 0)
					if (brd[y + (py * mult)][x + (px * mult)] == 'K')
						return (1);
				px++;
			}
			py++;
		}
		mult++;
	}
	return (0);
}
