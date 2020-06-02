/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randenc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:06:28 by anystrom          #+#    #+#             */
/*   Updated: 2020/06/02 14:25:47 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	draw_gfx(t_wolf *wlf, t_gfx gfx, int x, int y)
{
	int		gx;
	int		gy;

	gy = 0;
	while (gy < gfx.hgt)
	{
		gx = 0;
		while (gx < gfx.wid)
		{
			if (gfx.data[gfx.wid * gy + gx] != 0xff00ff)
				wlf->img.data[WINX * (y + gy) + (x + gx)] = gfx.data[gfx.wid *
						gy + gx];
			gx++;
		}
		gy++;
	}
}

void	draw_cursor(t_wolf *wlf, t_gfx gfx, int var)
{
	int		x;
	int		y;

	y = 520;
	if (var == 0)
		x = 6;
	else if (var == 1)
		x = 364;
	else if (var == 2)
		x = 722;
	else if (var == 3)
	{
		y = 619;
		x = 185;
	}
	else if (var == 4)
	{
		y = 619;
		x = 543;
	}
	else
		return ;
	draw_gfx(wlf, gfx, x, y);
}

void	draw_menu(t_wolf *wlf, int x, int y)
{
	int		gy;
	int		gx;

	gy = 0;
	while (gy < wlf->gfx[11].hgt)
	{
		gx = 0;
		while (gx < wlf->gfx[11].wid)
		{
			if (wlf->gfx[12].data[wlf->gfx[12].wid * gy + gx] == 0xff00ff)
				gx += 0;
			else if (gy > 7 + (wlf->cur * 50) && gy < 7 + ((wlf->cur + 1) * 50))
				wlf->img.data[WINX * (y + gy) + (x + gx)] =
						wlf->gfx[12].data[wlf->gfx[12].wid * gy + gx];
			else
				wlf->img.data[WINX * (y + gy) + (x + gx)] =
						wlf->gfx[11].data[wlf->gfx[11].wid * gy + gx];
			gx++;
		}
		gy++;
	}
}

void	encounter(t_wolf *wlf)
{
	wlf->img = init_image(wlf, WINX, WINY);
	draw_gfx(wlf, wlf->gfx[9], 0, 0);
	draw_gfx(wlf, wlf->gfx[10], 258, 112);
	draw_menu(wlf, 0, 150);
	draw_cursor(wlf, wlf->gfx[13], wlf->plr);
	draw_cursor(wlf, wlf->gfx[14], wlf->sel);
	mlx_put_image_to_window(wlf->mlx, wlf->win, wlf->img.img, 0, 0);
	mlx_destroy_image(wlf->mlx, wlf->img.img);
}
