/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randkey.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:48:24 by AleXwern          #+#    #+#             */
/*   Updated: 2020/05/25 14:48:24 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/value.h"
#include "../includes/wolf.h"

void				combat_key(int	key, t_wolf *wlf)
{
	wlf->isclick = 0;
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
	wlf->cycle(wlf);
}