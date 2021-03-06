/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:01:53 by anystrom          #+#    #+#             */
/*   Updated: 2020/06/02 14:32:50 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/value.h"
#include "../includes/wolf.h"

void	move_l(t_wolf *wlf, double olddirx, double oldplanex)
{
	if (wlf->keyleft)
	{
		olddirx = wlf->dirx;
		wlf->dirx = wlf->dirx * cos(wlf->rotsp) - wlf->diry * sin(wlf->rotsp);
		wlf->diry = olddirx * sin(wlf->rotsp) + wlf->diry * cos(wlf->rotsp);
		oldplanex = wlf->planex;
		wlf->planex = wlf->planex * cos(wlf->rotsp) - wlf->planey *
				sin(wlf->rotsp);
		wlf->planey = oldplanex * sin(wlf->rotsp) + wlf->planey *
				cos(wlf->rotsp);
		wlf->sbox += WINX / 64;
	}
}

int		move_lr(t_wolf *wlf)
{
	double	olddirx;
	double	oldplanex;

	if (wlf->keyright)
	{
		olddirx = wlf->dirx;
		wlf->dirx = wlf->dirx * cos(-wlf->rotsp) - wlf->diry * sin(-wlf->rotsp);
		wlf->diry = olddirx * sin(-wlf->rotsp) + wlf->diry * cos(-wlf->rotsp);
		oldplanex = wlf->planex;
		wlf->planex = wlf->planex * cos(-wlf->rotsp) - wlf->planey *
				sin(-wlf->rotsp);
		wlf->planey = oldplanex * sin(-wlf->rotsp) + wlf->planey *
				cos(-wlf->rotsp);
		wlf->sbox -= WINX / 64;
	}
	move_l(wlf, olddirx, oldplanex);
	if (wlf->sbox < 0)
		wlf->sbox += WINX;
	if (wlf->sbox > WINX)
		wlf->sbox -= WINX;
	return (0);
}

int		move_fb(t_wolf *wlf)
{
	if (wlf->keyup)
	{
		if (wlf->map[wlf->flr][(int)(wlf->posy + wlf->diry
				* wlf->movsp)][(int)wlf->posx] <= 1)
			wlf->posy += wlf->diry * wlf->movsp;
		if (wlf->map[wlf->flr][(int)wlf->posy][(int)(wlf->posx
				+ wlf->dirx * wlf->movsp)] <= 1)
			wlf->posx += wlf->dirx * wlf->movsp;
	}
	if (wlf->keydown)
	{
		if (wlf->map[wlf->flr][(int)(wlf->posy - wlf->diry
				* wlf->movsp)][(int)wlf->posx] <= 1)
			wlf->posy -= wlf->diry * wlf->movsp;
		if (wlf->map[wlf->flr][(int)wlf->posy][(int)(wlf->posx
				- wlf->dirx * wlf->movsp)] <= 1)
			wlf->posx -= wlf->dirx * wlf->movsp;
	}
	wlf->aggro += (int)wlf->rng % 7;
	return (0);
}
