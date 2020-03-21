/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JessicaNystrom <JessicaNystrom@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:38:13 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/21 18:17:08 by JessicaNyst      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"
#include <stdio.h> //DELETE

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
	while (wlf->start <= wlf->end)
	{
		if (wlf->texbool)
		{
			wlf->texy = abs((((wlf->start * 256 - WINY * 128 + wlf->lineh * 128) * 64)
						/ wlf->lineh) / 256);
			wlf->img.data[WINX * wlf->start + wlf->x] = wlf->gfx[2].data[wlf->texy % 64 * wlf->gfx[2].sizel + wlf->texx % 64 * wlf->gfx[2].bpp / 2];
		}
		else
		{
			//printf("Pixel coords %d %d\n", wlf->x, wlf->start);
			wlf->img.data[WINX * wlf->start + wlf->x] = wlf->testcolor;
			//mlx_pixel_put(wlf->mlx, wlf->win, wlf->x, wlf->start, wlf->testcolor);
			//printf("Set pixel at Y%d X%d\n", wlf->start, wlf->x);
			//mlx_put_image_to_window(wlf->mlx, wlf->win, wlf->img.img, 0, 0);
		}
		wlf->start++;
	}
}