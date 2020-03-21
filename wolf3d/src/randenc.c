/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randenc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:06:28 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/13 12:06:15 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	testfunc(t_wolf *wlf)
{
	while (wlf->fcomb == 0)
	{
		wlf->rng += (wlf->posx - wlf->posy) * 10;
		if (wlf->rng < 0)
			wlf->rng = 35565;
		else if (wlf->rng > 35565)
			wlf->rng = 0;
	}
}