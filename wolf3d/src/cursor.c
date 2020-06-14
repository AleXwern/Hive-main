/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:29:44 by anystrom          #+#    #+#             */
/*   Updated: 2020/06/14 13:47:41 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/value.h"
#include "../includes/wolf.h"

void	cur_zero(t_wolf *wlf, int tar)
{
	wlf->chara[wlf->plr].action = 1;
	gen_att_ai(wlf);
	tar = wlf->chara[wlf->plr].target;
	wlf->chara[wlf->chara[wlf->plr].target].hp -= 20 * wlf->chara[tar].row
			* wlf->chara[tar].defend;
	wlf->chara[wlf->plr].defend = 2;
}

void	cur_two(t_wolf *wlf, int tar)
{
	wlf->chara[wlf->plr].action = 3;
	gen_att_ai(wlf);
	tar = wlf->chara[wlf->plr].target;
	wlf->chara[wlf->chara[wlf->plr].target].hp -= 30 * wlf->chara[tar].row
			* wlf->chara[tar].defend;
	wlf->chara[wlf->plr].defend = 4;
}
