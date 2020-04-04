/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randenc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:06:28 by anystrom          #+#    #+#             */
/*   Updated: 2020/04/04 13:32:56 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	testfunc(t_wolf *wlf)
{
	int		i;

	while (wlf->fcomb == 0)
	{
		i = 0;
		ft_sleep(10000);
		while (i++ < 10000)
		{
			wlf->rng += (wlf->posx - wlf->posy) * 10;
			if (wlf->rng < 0)
				wlf->rng = 35565;
			else if (wlf->rng > 35565)
				wlf->rng = 0;
		}
	}
}

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
			wlf->img.data[WINX * (y + gy) + (x + gx)] = gfx.data[gfx.wid * gy + gx];
			gx++;
		}
		gy++;
	}
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
			if (gy > 8 + (wlf->cur * 50) && gy < 8 + ((wlf->cur + 1) * 50))
				wlf->img.data[WINX * (y + gy) + (x + gx)] = wlf->gfx[12].data[wlf->gfx[12].wid * gy + gx];
			else
				wlf->img.data[WINX * (y + gy) + (x + gx)] = wlf->gfx[11].data[wlf->gfx[11].wid * gy + gx];
			gx++;
		}
		gy++;
	}
}

void	encounter(t_wolf *wlf)
{
	wlf->img = init_image(wlf, WINX, WINY);
	draw_gfx(wlf, wlf->gfx[9], 0, 0);
	draw_gfx(wlf, wlf->gfx[10], 490, 290);
	draw_menu(wlf, 0, 150);
	mlx_put_image_to_window(wlf->mlx, wlf->win, wlf->img.img, 0, 0);
	mlx_destroy_image(wlf->mlx, wlf->img.img);
}