/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:38:13 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/11 15:55:50 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	wall_stripe(t_wolf *wlf)
{
	wlf->texnum = wlf->map[wlf->flr][wlf->mapx][wlf->mapy];
	if (wlf->side == 0)
		wlf->wallx = wlf->posy + wlf->walldist * wlf->raydy;
	else
		wlf->wallx = wlf->posx + wlf->walldist * wlf->raydx;
	wlf->wallx -= floor(wlf->wallx);
	wlf->texx = (int)(wlf->wallx * 64.0);
	if (wlf->side == 0 && wlf->raydx > 0)
		wlf->texx = 64 - wlf->texx - 1;
	if (wlf->side == 1 && wlf->raydx < 0)
		wlf->texx = 64 - wlf->texx - 1;
	while (++wlf->start <= wlf->end)
	{
		ft_memcpy(wlf->img.data + 4 * WINX * wlf->start + wlf->x * 4,
				&wlf->testcolor, sizeof(int));
	}
}