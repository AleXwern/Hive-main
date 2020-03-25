/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randenc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:06:28 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/25 13:26:12 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	testfunc(t_wolf *wlf)
{
	int		i;

	while (wlf->fcomb == 0)
	{
		i = 0;
		while (i++ < 10000)
		{
			wlf->rng += (wlf->posx - wlf->posy) * 10;
			if (wlf->rng < 0)
				wlf->rng = 35565;
			else if (wlf->rng > 35565)
				wlf->rng = 0;
		}
	}
}