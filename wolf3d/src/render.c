/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:25:29 by anystrom          #+#    #+#             */
/*   Updated: 2020/08/10 13:38:01 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	ray_check(t_wolf *wlf)
{
	wlf->hit = 0;
	while (wlf->hit == 0)
	{
		if (wlf->sidedx < wlf->sidedy)
		{
			wlf->sidedx += wlf->deltadx;
			wlf->mapx += wlf->stepx;
			wlf->side = 0;
		}
		else
		{
			wlf->sidedy += wlf->deltady;
			wlf->mapy += wlf->stepy;
			wlf->side = 1;
		}
		if (wlf->map[wlf->flr][wlf->mapy][wlf->mapx] > 1)
			wlf->hit = 1;
	}
}

void	ray_prep(t_wolf *wlf)
{
	wlf->deltadx = fabs(1 / wlf->raydx);
	wlf->deltady = fabs(1 / wlf->raydy);
	if (wlf->raydx < 0)
	{
		wlf->stepx = -1;
		wlf->sidedx = (wlf->posx - wlf->mapx) * wlf->deltadx;
	}
	else
	{
		wlf->stepx = 1;
		wlf->sidedx = (wlf->mapx + 1.0 - wlf->posx) * wlf->deltadx;
	}
	if (wlf->raydy < 0)
	{
		wlf->stepy = -1;
		wlf->sidedy = (wlf->posy - wlf->mapy) * wlf->deltady;
	}
	else
	{
		wlf->stepy = 1;
		wlf->sidedy = (wlf->mapy + 1.0 - wlf->posy) * wlf->deltady;
	}
}

void	rc_init(t_wolf *wlf)
{
	wlf->camx = 2 * wlf->x / (double)(WINX) - 1.0;
	wlf->raydx = wlf->dirx + wlf->planex * wlf->camx;
	wlf->raydy = wlf->diry + wlf->planey * wlf->camx;
	wlf->mapx = (int)wlf->posx;
	wlf->mapy = (int)wlf->posy;
	ray_prep(wlf);
	ray_check(wlf);
	if (wlf->side == 0)
		wlf->walldist = (wlf->mapx - wlf->posx + (1 - wlf->stepx) / 2) /
				wlf->raydx;
	else
		wlf->walldist = (wlf->mapy - wlf->posy + (1 - wlf->stepy) / 2) /
				wlf->raydy;
	if (wlf->walldist < 0.0001)
		wlf->walldist += 0.01;
}

void	side_check(t_wolf* wlf)
{
	int	delta;

	if (wlf->side == 0)
		delta = wlf->posx - wlf->mapx;
	else
		delta = wlf->posy - wlf->mapy;
	if (delta > 0)
		wlf->side += 2;
	if (wlf->side == 0)
		wlf->testcolor = 0x3679ff;
	else if (wlf->side == 1)
		wlf->testcolor = 0xb01cff;
	else if (wlf->side == 2)
		wlf->testcolor = 0x1c03fc;
	else
		wlf->testcolor = 0x6a3396;
}

void	render(t_wolf *wlf)
{
	wlf->img = init_image(wlf, WINX, WINY);
	wlf->x = -1;
	render_floor(wlf, 0);
	while (++wlf->x < WINX)
	{
		rc_init(wlf);
		wlf->lineh = (int)(WINY / wlf->walldist);
		side_check(wlf);
		wlf->start = -wlf->lineh / 2 + WINY / 2;
		if (wlf->start < 0)
			wlf->start = 0;
		wlf->end = wlf->lineh / 2 + WINY / 2;
		if (wlf->end >= WINY)
			wlf->end = WINY - 1;
		wall_stripe(wlf);
	}
	if (wlf->flrchange > 0)
		draw_gfx(wlf, wlf->gfx[wlf->updown], 0, 0);
	mlx_put_image_to_window(wlf->mlx, wlf->win, wlf->img.img, 0, 0);
	mlx_destroy_image(wlf->mlx, wlf->img.img);
}
