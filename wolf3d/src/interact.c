/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 14:03:32 by AleXwern          #+#    #+#             */
/*   Updated: 2020/04/15 11:55:37 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	lab_move(t_wolf *wlf, int obj)
{
	if (obj == 3 && wlf->flr < wlf->mxflr && wlf->map[wlf->flr + 1][(int)wlf->posy][(int)wlf->posx] == 1)
		wlf->flr++;
	else if (obj == 4 && wlf->flr > 0 && wlf->map[wlf->flr - 1][(int)wlf->posy][(int)wlf->posx] == 1)
		wlf->flr--;
	else if ((obj == 3 && wlf->flr == wlf->mxflr) || (obj == 4 && wlf->flr == 0))
		error_out(LAB_OUT, wlf);
	wlf->dirx *= -1.0;
	wlf->diry *= -1.0;
	wlf->planex *= -1.0;
	wlf->planey *= -1.0;
	wlf->cycle(wlf);
	mlx_put_image_to_window(wlf->mlx, wlf->win, wlf->gfx[obj + 4].img, 0, 0);
}