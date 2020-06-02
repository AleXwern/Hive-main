/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 01:20:40 by AleXwern          #+#    #+#             */
/*   Updated: 2020/06/02 14:37:49 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	draw_floor(t_wolf *wlf, int y)
{
	int		x;

	x = 0;
	while (x < WINX)
	{
		if (wlf->texbool)
		{
			wlf->cellx = (int)wlf->floorx;
			wlf->celly = (int)wlf->floory;
			wlf->tx = (int)(128 * (wlf->floorx - wlf->cellx)) & (128 - 1);
			wlf->ty = (int)(128 * (wlf->floory - wlf->celly)) & (128 - 1);
			wlf->floorx += wlf->flstepx;
			wlf->floory += wlf->flstepy;
			wlf->img.data[WINX * y + x] = wlf->gfx[1].data[128 *
					wlf->ty + wlf->tx];
		}
		else
			wlf->img.data[WINX * y + x] = 0x0f9926;
		x++;
	}
}

void	render_floor(t_wolf *wlf, int y)
{
	y = WINY / 2;
	wlf->raydx0 = wlf->dirx - wlf->planex;
	wlf->raydy0 = wlf->diry - wlf->planey;
	wlf->raydx1 = wlf->dirx + wlf->planex;
	wlf->raydy1 = wlf->diry + wlf->planey;
	while (y < WINY)
	{
		wlf->pos = y - WINY / 2;
		wlf->posz = WINY * 0.5;
		wlf->rowdist = wlf->posz / wlf->pos;
		wlf->flstepx = wlf->rowdist * (wlf->raydx1 - wlf->raydx0) / WINX;
		wlf->flstepy = wlf->rowdist * (wlf->raydy1 - wlf->raydy0) / WINX;
		wlf->floorx = wlf->posx + wlf->rowdist * wlf->raydx0;
		wlf->floory = wlf->posy + wlf->rowdist * wlf->raydy0;
		draw_floor(wlf, y);
		y++;
	}
}

void	move_skybox(t_wolf *wlf)
{
	double	adjy;

	wlf->sbox = 0;
	adjy = (wlf->diry + 1.0) / 2;
	if (wlf->dirx > 0)
	{
		wlf->sbox = WINX * adjy;
	}
	else
	{
		wlf->sbox = WINX - WINX * adjy;
	}
}
