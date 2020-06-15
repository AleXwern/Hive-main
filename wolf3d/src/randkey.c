/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randkey.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:29:44 by anystrom          #+#    #+#             */
/*   Updated: 2020/06/15 13:59:24 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/value.h"
#include "../includes/wolf.h"

void				health_check(t_wolf *wlf, int pc, int thp)
{
	if (wlf->chara[5].hp <= 0)
	{
		exit_combat(wlf);
		return ;
	}
	while (++pc < 5)
	{
		if (wlf->chara[pc].hp < 0)
			wlf->chara[pc].hp = 0;
		thp += wlf->chara[pc].hp;
	}
	if (thp <= 0)
		error_out(GAME_OVER, wlf, 0);
	while (wlf->chara[wlf->plr].hp <= 0 && wlf->plr < 5)
		wlf->plr++;
}

void				combat_key_exttre(int key, t_wolf *wlf)
{
	if (key == RIGHT && wlf->sel != -1)
	{
		wlf->sel--;
		if (wlf->sel < 0)
			wlf->sel = 4;
	}
	else if (key == LEFT && wlf->sel != -1)
	{
		wlf->sel++;
		if (wlf->sel > 4)
			wlf->sel = 0;
	}
	else if (key == KEY_C && wlf->sel > -1)
		wlf->sel = -1;
}

void				combat_key_exttwo(int key, t_wolf *wlf)
{
	int		hp;

	if (key == SPACE && wlf->sel != -1)
	{
		wlf->chara[wlf->plr].action = 2;
		wlf->chara[wlf->plr].defend = 2;
		wlf->chara[wlf->plr].target = wlf->sel;
		wlf->chara[wlf->chara[wlf->plr].target].hp += 45;
		hp = wlf->chara[wlf->chara[wlf->plr].target].hp;
		if (hp > wlf->chara[wlf->chara[wlf->plr].target].maxhp)
		{
			hp = wlf->chara[wlf->chara[wlf->plr].target].maxhp;
			wlf->chara[wlf->chara[wlf->plr].target].hp = hp;
		}
		wlf->sel = -1;
		wlf->cur = 0;
		wlf->plr++;
	}
	else
		combat_key_exttre(key, wlf);
}

void				combat_key_ext(int key, t_wolf *wlf, int tar)
{
	if (key == SPACE && wlf->sel == -1)
	{
		if (wlf->cur == 0)
			cur_zero(wlf, tar);
		else if (wlf->cur == 1)
		{
			wlf->chara[wlf->plr].action = 4;
			wlf->chara[wlf->plr].defend = 1;
		}
		else if (wlf->cur == 2)
			cur_two(wlf, tar);
		else if (wlf->cur == 4)
			wlf->sel = 0;
		else if (wlf->cur == 5)
			exit_combat(wlf);
		if (wlf->cur != 4 && wlf->cur != 5)
		{
			wlf->plr++;
			wlf->cur = 0;
		}
	}
	else
		combat_key_exttwo(key, wlf);
}

void				combat_key(int key, t_wolf *wlf)
{
	if (wlf->plr >= 5)
	{
		gen_att_ai(wlf);
		wlf->plr = 0;
	}
	else if (key == UP && wlf->sel == -1)
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
	else
		combat_key_ext(key, wlf, 0);
	health_check(wlf, -1, 0);
	wlf->cycle(wlf);
}
