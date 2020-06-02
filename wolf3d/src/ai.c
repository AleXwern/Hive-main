/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:23:24 by anystrom          #+#    #+#             */
/*   Updated: 2020/06/02 16:33:00 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	gen_att_ai(t_wolf *wlf)
{
	if (wlf->plrck < 5)
		wlf->chara[wlf->plrck].target = 5;
	else
	{
		if ((int)wlf->rng % 99 < 66)
			wlf->chara[wlf->plrck].target = (int)wlf->rng % 3;
		else
			wlf->chara[wlf->plrck].target = (int)wlf->rng % 2 + 3;
	}
}