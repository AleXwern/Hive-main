/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:38:13 by anystrom          #+#    #+#             */
/*   Updated: 2020/08/12 12:05:20 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	draw_sky(t_wolf *wlf, int scan)
{
	int		i;

	if (scan >= WINX)
		scan -= WINX;
	i = 0;
	while (i < wlf->start)
	{
		if (wlf->texbool)
			wlf->img.data[WINX * i + wlf->x] = wlf->gfx[0].data[WINX *
					i + scan];
		else
			wlf->img.data[WINX * i + wlf->x] = 0x00c8ff;
		i++;
	}
}

void	draw_stripe(t_wolf *wlf)
{
	while (wlf->start <= wlf->end)
	{
		if (wlf->texbool)
		{
			wlf->texy = abs((((wlf->start * 256 - WINY * 128 + wlf->lineh
					* 128) * 128)
						/ wlf->lineh) / 256);
			wlf->testcolor = wlf->gfx[wlf->texnum].data[wlf->texy % 128 *
					wlf->gfx[2].sizel / 4 + wlf->texx %
					128 * wlf->gfx[2].bpp / 32];
			if (wlf->side > 1)
				wlf->testcolor = (wlf->testcolor >> 1) & 0x7f7f7f;
		}
		wlf->img.data[WINX * wlf->start + wlf->x] = wlf->testcolor;
		wlf->start++;
	}
}

void	wall_stripe(t_wolf *wlf)
{
	if (wlf->texbool)
	{
		wlf->texnum = wlf->map[wlf->flr][wlf->mapy][wlf->mapx];
		if (wlf->side % 2 == 0)
			wlf->wallx = wlf->posy + wlf->walldist * wlf->raydy;
		else
			wlf->wallx = wlf->posx + wlf->walldist * wlf->raydx;
		wlf->wallx -= floor(wlf->wallx);
		wlf->texx = (int)(wlf->wallx * 128.0);
		if (wlf->side % 2 == 0 && wlf->raydx > 0)
			wlf->texx = 128 - wlf->texx - 1;
		if (wlf->side % 2 == 1 && wlf->raydy < 0)
			wlf->texx = 128 - wlf->texx - 1;
	}
	else if (wlf->map[wlf->flr][wlf->mapy][wlf->mapx] != 2)
		wlf->testcolor = 0x22a800;
	draw_sky(wlf, wlf->sbox + wlf->x);
	draw_stripe(wlf);
}
