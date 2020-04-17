/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:07:30 by anystrom          #+#    #+#             */
/*   Updated: 2020/04/17 15:31:04 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/value.h"
#include "../includes/wolf.h"

void				combat_key(int	key, t_wolf *wlf)
{
	if (key == UP && wlf->sel == -1)
	{
		wlf->cur--;
		if (wlf->cur < 0)
			wlf->cur = 5;
		else if (wlf->cur == 3)
			wlf->cur = 2;
	}
	else if (key == DOWN && wlf->sel == -1)
	{
		wlf->cur++;
		if (wlf->cur > 5)
			wlf->cur = 0;
		else if (wlf->cur == 3)
			wlf->cur = 4;
	}
	else if (key == SPACE && wlf->cur != -1)
	{
		if (wlf->cur == 4)
			wlf->sel = 0;
		else if (wlf->cur == 5)
		{
			wlf->aggro = 0;
			wlf->cycle = &render;
		}
		else
			wlf->plr++;
		if (wlf->plr > 4)
			wlf->plr = 0;
	}
	else if (key == KEY_C && wlf->sel > -1)
		wlf->sel = -1;
	else if (key == LEFT && wlf->sel != -1)
	{
		wlf->sel++;
		if (wlf->sel > 4)
			wlf->sel = 0;
	}
	else if (key == RIGHT && wlf->sel != -1)
	{
		wlf->sel--;
		if (wlf->sel < 0)
			wlf->sel = 4;
	}
	//ft_sleep(300000);
	wlf->cycle(wlf);
}

int				key_press(int key, t_wolf *wlf)
{
	//ft_putnbrln(key);
	if (key == ESC)
		error_out(FINE, wlf);
	else if (wlf->aggro > 500)
		combat_key(key, wlf);
	else if (key == LEFT || key == RIGHT)
		move_lr(key, wlf);
	else if (key == UP || key == DOWN)
		move_fb(key, wlf);
	else if (key == KEY_T)
		wlf->texbool = (wlf->texbool * wlf->texbool) - 1;
	else if (key == SPACE)
		interact(wlf);
	else if (key == KEY_C)
		wlf->aggro = 499;
	return (0);
}

int				key_release(int key, t_wolf *wlf)
{
	return (0);
}

int				x_press(t_wolf *wolf)
{
	error_out(FINE, wolf);
	return (0);
}
