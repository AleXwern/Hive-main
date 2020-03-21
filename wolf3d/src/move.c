/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:01:53 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/13 13:09:27 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/value.h"
#include "../includes/wolf.h"

int		move_lr(int key, t_wolf *wlf)
{
	double	olddirx;
	double	oldplanex;

	if (key == RIGHT)
	{
		olddirx = wlf->dirx;
		wlf->dirx = wlf->dirx * cos(-wlf->rotsp) - wlf->diry * sin(-wlf->rotsp);
		wlf->diry = olddirx * sin(-wlf->rotsp) + wlf->diry * cos(-wlf->rotsp);
		oldplanex = wlf->planex;
		wlf->planex = wlf->planex * cos(-wlf->rotsp) - wlf->planey * sin(-wlf->rotsp);
		wlf->planey = oldplanex * sin(-wlf->rotsp) + wlf->planey * cos(-wlf->rotsp);
	}
	if (key == LEFT)
	{
		olddirx = wlf->dirx;
		wlf->dirx = wlf->dirx * cos(wlf->rotsp) - wlf->diry * sin(wlf->rotsp);
		wlf->diry = olddirx * sin(wlf->rotsp) + wlf->diry * cos(wlf->rotsp);
		oldplanex = wlf->planex;
		wlf->planex = wlf->planex * cos(wlf->rotsp) - wlf->planey * sin(wlf->rotsp);
		wlf->planey = oldplanex * sin(wlf->rotsp) + wlf->planey * cos(wlf->rotsp);
	}
	//mlx_clear_window(wlf->mlx, wlf->win);
	render(wlf);
	return (0);
}

int		move_fb(int key, t_wolf *wlf)
{
	if (key == UP)
	{
		if (wlf->map[wlf->flr][(int)(wlf->posx + wlf->dirx * wlf->movsp)][(int)wlf->posy] == 1)
			wlf->posx += wlf->dirx * wlf->movsp;
		if (wlf->map[wlf->flr][(int)wlf->posx][(int)(wlf->posy + wlf->diry * wlf->movsp)] == 1)
			wlf->posy += wlf->diry * wlf->movsp;
	}
	if (key == DOWN)
	{
		if (wlf->map[wlf->flr][(int)(wlf->posx - wlf->dirx * wlf->movsp)][(int)wlf->posy] == 1)
			wlf->posx -= wlf->dirx * wlf->movsp;
		if (wlf->map[wlf->flr][(int)wlf->posx][(int)(wlf->posy - wlf->diry * wlf->movsp)] == 1)
			wlf->posy -= wlf->diry * wlf->movsp;
	}
	wlf->aggro += (int)wlf->rng % 7;
	//mlx_clear_window(wlf->mlx, wlf->win);
	render(wlf);
	return (0);
}