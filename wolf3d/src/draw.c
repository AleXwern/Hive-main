/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:38:13 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/13 13:42:55 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	wall_stripe(t_wolf *wlf)
{
	if (wlf->texbool == 1)
	{
		wlf->texnum = wlf->map[wlf->flr][wlf->mapx][wlf->mapy];
		if (wlf->side == 0)
			wlf->wallx = wlf->posy + wlf->walldist * wlf->raydy;
		else
			wlf->wallx = wlf->posx + wlf->walldist * wlf->raydx;
		wlf->wallx -= floor(wlf->wallx);
		wlf->texx = (int)(wlf->wallx * 64.0);
		if (wlf->side == 0 && wlf->raydx > 0)
			wlf->texx = 64 - wlf->texx - 1;
		if (wlf->side == 1 && wlf->raydx < 0)
			wlf->texx = 64 - wlf->texx - 1;
	}
	while (wlf->start <= wlf->end)
	{
		if (wlf->texbool == 1)
		{
			wlf->texy = abs((((wlf->start * 256 - WINY * 128 + wlf->lineh * 128) * 64)
						/ wlf->lineh) / 256);
			wlf->img.data[WINX * wlf->start + wlf->x] = wlf->gfx[2].data[wlf->texy % 64 * wlf->gfx[2].sizel + wlf->texx % 64 * wlf->gfx[2].bpp / 2];
		}
		else
		{
			wlf->img.data[WINX * wlf->start + wlf->x] = wlf->testcolor;
		}
		wlf->start++;
	}
}