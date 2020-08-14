/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:23:24 by anystrom          #+#    #+#             */
/*   Updated: 2020/08/12 12:08:38 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	foe_ai(t_wolf *wlf, int tar)
{
	if ((int)wlf->rng % 1000 < 600)
	{
		wlf->chara[wlf->plr].action = 1;
		tar = wlf->chara[wlf->plr].target;
		wlf->chara[wlf->chara[wlf->plr].target].hp -= 20 *
				wlf->chara[tar].row * wlf->chara[tar].defend;
		wlf->chara[wlf->plr].defend = 2;
	}
	else if ((int)wlf->rng % 1000 < 850)
	{
		wlf->chara[wlf->plr].action = 3;
		tar = wlf->chara[wlf->plr].target;
		wlf->chara[wlf->chara[wlf->plr].target].hp -= 30 *
				wlf->chara[tar].row * wlf->chara[tar].defend;
		wlf->chara[wlf->plr].defend = 4;
	}
	else
	{
		wlf->chara[wlf->plr].action = 4;
		wlf->chara[wlf->plr].defend = 1;
	}
}

void	gen_att_ai(t_wolf *wlf)
{
	int		i;

	if (wlf->plrck < 5)
		wlf->chara[wlf->plr].target = 5;
	else
	{
		if ((int)wlf->rng % 100 < 66)
			wlf->chara[wlf->plr].target = (int)wlf->rng % 3;
		else
			wlf->chara[wlf->plr].target = (int)wlf->rng % 2 + 3;
		if (wlf->chara[wlf->chara[wlf->plr].target].hp <= 0)
		{
			i = 0;
			while (wlf->chara[i].hp <= 0 && i < 4)
				i++;
			wlf->chara[wlf->plr].target = i;
		}
		foe_ai(wlf, 0);
	}
	wlf->rng += (wlf->posx + wlf->posy) * 17;
	if (wlf->rng < 0)
		wlf->rng = 35565;
	else if (wlf->rng > 35565)
		wlf->rng = 0;
}
