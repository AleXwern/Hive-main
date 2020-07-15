/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:07:30 by anystrom          #+#    #+#             */
/*   Updated: 2020/06/15 14:30:17 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/value.h"
#include "../includes/wolf.h"

int				key_hold(int key, t_wolf *wlf)
{
	if (key == ESC)
		error_out(FINE, wlf, 0);
	if (key == LEFT)
		wlf->keyleft = 1;
	if (key == RIGHT)
		wlf->keyright = 1;
	if (key == UP)
		wlf->keyup = 1;
	if (key == DOWN)
		wlf->keydown = 1;
	return (0);
}

int				key_release(int key, t_wolf *wlf)
{
	if (wlf->aggro > MAXAGGRO)
		combat_key(key, wlf);
	if (wlf->aggro > MAXAGGRO)
		return (0);
	if (key == KEY_T)
		wlf->texbool = (wlf->texbool * wlf->texbool) - 1;
	if (key == SPACE)
		interact(wlf);
	if (key == KEY_C)
		wlf->aggro = MAXAGGRO - 10;
	if (key == LEFT)
		wlf->keyleft = 0;
	if (key == RIGHT)
		wlf->keyright = 0;
	if (key == UP)
		wlf->keyup = 0;
	if (key == DOWN)
		wlf->keydown = 0;
	return (0);
}

int				x_press(t_wolf *wlf)
{
	error_out(FINE, wlf, 0);
	return (0);
}

int				move(t_wolf *wlf)
{
	if (wlf->flrchange > 0)
		wlf->flrchange--;
	if (wlf->aggro > MAXAGGRO)
	{
		wlf->cycle = &encounter;
		return (0);
	}
	if (wlf->keydown || wlf->keyup)
	{
		move_fb(wlf);
		wlf->rng += (wlf->posx + wlf->posy) * 10;
		if (wlf->rng < 0)
			wlf->rng = 35565;
		else if (wlf->rng > 35565)
			wlf->rng = 0;
	}
	if (wlf->keyleft || wlf->keyright)
		move_lr(wlf);
	wlf->cycle(wlf);
	return (0);
}
