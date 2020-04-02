/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randenc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:06:28 by anystrom          #+#    #+#             */
/*   Updated: 2020/04/02 19:53:25 by AleXwern         ###   ########.fr       */
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
		ft_sleep(10000);
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

void	encounter(t_wolf *wlf)
{
	mlx_clear_window(wlf->mlx, wlf->win);
	mlx_put_image_to_window(wlf->mlx, wlf->win, wlf->gfx[10].img, 0, 0);
	mlx_put_image_to_window(wlf->mlx, wlf->win, wlf->gfx[9].img, 0, 0);
}