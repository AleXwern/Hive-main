/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 14:03:32 by AleXwern          #+#    #+#             */
/*   Updated: 2020/03/24 14:18:33 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	lab_move(t_wolf *wlf, int obj)
{
	if (obj == 3 && wlf->flr < 4 && wlf->map[wlf->flr + 1][(int)wlf->posx][(int)wlf->posy] == 1)
		wlf->flr++;
	else if (obj == 4 && wlf->flr > 0 && wlf->map[wlf->flr - 1][(int)wlf->posx][(int)wlf->posy] == 1)
		wlf->flr--;
	wlf->dirx *= -1.0;
	wlf->diry *= -1.0;
	wlf->planex *= -1.0;
	wlf->planey *= -1.0;
	render(wlf);
}