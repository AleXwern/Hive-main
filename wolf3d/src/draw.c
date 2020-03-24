/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:38:13 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/24 14:26:53 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"
#include <stdio.h> //DELETE

void	draw_sky(t_wolf *wlf, int scan)
{
	int		i;

	if (scan >= WINX)
		scan -= WINX;
	i = 0;
	while (i < wlf->start)
	{
		if (wlf->texbool)
			wlf->img.data[WINX * i + wlf->x] = wlf->gfx[0].data[WINX * i + scan];
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
			wlf->texy = abs((((wlf->start * 256 - WINY * 128 + wlf->lineh * 128) * 64)
						/ wlf->lineh) / 256);
			wlf->img.data[WINX * wlf->start + wlf->x] = wlf->gfx[wlf->texnum].data[wlf->texy % 64 * wlf->gfx[2].sizel / 4 + wlf->texx % 64 * wlf->gfx[2].bpp / 32];
		}
		else
			wlf->img.data[WINX * wlf->start + wlf->x] = wlf->testcolor;
		wlf->start++;
	}
}

void	wall_stripe(t_wolf *wlf)
{
	if (wlf->texbool)
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
	draw_sky(wlf, wlf->sbox + wlf->x);
	draw_stripe(wlf);
}
