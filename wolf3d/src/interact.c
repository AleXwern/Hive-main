/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 14:03:32 by AleXwern          #+#    #+#             */
/*   Updated: 2020/06/15 13:58:30 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	lab_move(t_wolf *wlf, int obj)
{
	int		flrcmp;

	flrcmp = wlf->flr;
	if (obj == 3 && wlf->flr < wlf->mxflr && wlf->map[wlf->flr +
			1][(int)wlf->posy][(int)wlf->posx] == 1)
		wlf->flr++;
	else if (obj == 4 && wlf->flr > 0 && wlf->map[wlf->flr -
			1][(int)wlf->posy][(int)wlf->posx] == 1)
		wlf->flr--;
	else if ((obj == 3 && wlf->flr == wlf->mxflr) ||
			(obj == 4 && wlf->flr == 0))
		error_out(LAB_OUT, wlf, 0);
	if (flrcmp != wlf->flr)
	{
		wlf->dirx *= -1.0;
		wlf->diry *= -1.0;
		wlf->planex *= -1.0;
		wlf->planey *= -1.0;
		wlf->flrchange = 90;
		if (flrcmp < wlf->flr)
			wlf->updown = 8;
		else
			wlf->updown = 7;
	}
	wlf->cycle(wlf);
}

int		interact(t_wolf *wlf)
{
	double	tarposx;
	double	tarposy;
	int		obj;

	tarposx = wlf->posx + wlf->dirx * 0.9;
	tarposy = wlf->posy + wlf->diry * 0.9;
	obj = wlf->map[wlf->flr][(int)tarposy][(int)tarposx];
	if (obj == 3 || obj == 4)
		lab_move(wlf, obj);
	else if (obj == 5)
		wlf->map[wlf->flr][(int)tarposy][(int)tarposx] = 0;
	else if (obj == 0)
		wlf->map[wlf->flr][(int)tarposy][(int)tarposx] = 5;
	if (obj == 5 || obj == 0)
		wlf->cycle(wlf);
	return (0);
}
