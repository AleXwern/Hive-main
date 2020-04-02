/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:01:53 by anystrom          #+#    #+#             */
/*   Updated: 2020/04/01 16:35:49 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/value.h"
#include "../includes/wolf.h"
#include <stdio.h> //DELETE

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
	printf("Skybox mod %d\n", wlf->sbox);
}

int		interact(t_wolf *wlf)
{
	double	tarposx;
	double	tarposy;
	int		obj;

	tarposx = wlf->posx + wlf->dirx * 0.9;
	tarposy = wlf->posy + wlf->diry * 0.9;
	obj = wlf->map[wlf->flr][(int)tarposx][(int)tarposy];
	if (obj == 3 || obj == 4)
		lab_move(wlf, obj);
	else if (obj == 5)
		wlf->map[wlf->flr][(int)tarposx][(int)tarposy] = 0;
	else if (obj == 0)
		wlf->map[wlf->flr][(int)tarposx][(int)tarposy] = 5;
	if (obj == 5 || obj == 0)
		wlf->cycle(wlf);
	printf("Interacted with %d at %f %f\n", wlf->map[wlf->flr][(int)tarposx][(int)tarposy], tarposx, tarposy);
	return (0);
}

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
		wlf->sbox -= WINX / 64;
	}
	if (key == LEFT)
	{
		olddirx = wlf->dirx;
		wlf->dirx = wlf->dirx * cos(wlf->rotsp) - wlf->diry * sin(wlf->rotsp);
		wlf->diry = olddirx * sin(wlf->rotsp) + wlf->diry * cos(wlf->rotsp);
		oldplanex = wlf->planex;
		wlf->planex = wlf->planex * cos(wlf->rotsp) - wlf->planey * sin(wlf->rotsp);
		wlf->planey = oldplanex * sin(wlf->rotsp) + wlf->planey * cos(wlf->rotsp);
		wlf->sbox += WINX / 64;
	}
	if (wlf->sbox < 0)
		wlf->sbox += WINX;
	if (wlf->sbox > WINX)
		wlf->sbox -= WINX;
	wlf->cycle(wlf);
	return (0);
}

int		move_fb(int key, t_wolf *wlf)
{
	if (key == UP)
	{
		if (wlf->map[wlf->flr][(int)(wlf->posx + wlf->dirx * wlf->movsp)][(int)wlf->posy] <= 1)
			wlf->posx += wlf->dirx * wlf->movsp;
		if (wlf->map[wlf->flr][(int)wlf->posx][(int)(wlf->posy + wlf->diry * wlf->movsp)] <= 1)
			wlf->posy += wlf->diry * wlf->movsp;
	}
	if (key == DOWN)
	{
		if (wlf->map[wlf->flr][(int)(wlf->posx - wlf->dirx * wlf->movsp)][(int)wlf->posy] <= 1)
			wlf->posx -= wlf->dirx * wlf->movsp;
		if (wlf->map[wlf->flr][(int)wlf->posx][(int)(wlf->posy - wlf->diry * wlf->movsp)] <= 1)
			wlf->posy -= wlf->diry * wlf->movsp;
	}
	wlf->aggro += (int)wlf->rng % 7;
	if (wlf->aggro > 500)
		wlf->cycle = &encounter;
	wlf->cycle(wlf);
	return (0);
}