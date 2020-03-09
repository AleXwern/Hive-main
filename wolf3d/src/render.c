/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:25:29 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/09 16:12:14 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	rc_init(t_wolf *wlf)
{
	wlf->camx = 2 * wlf->x / (WINY - 1);
	wlf->raydx = wlf->dirx + (wlf->planex * wlf->camx);
	wlf->raydx = wlf->diry + (wlf->planey * wlf->camx);
}

void	render(t_wolf *wlf)
{
	wlf->img = init_image(wlf, WINX, WINY);
	wlf->x = 0;
	while (wlf->x < WINX)
	{
		rc_init(wlf);
	}
	mlx_put_image_to_window(wlf->mlx, wlf->win, wlf->img.img, 0, 0);
	mlx_destroy_image(wlf->mlx, wlf->img.img)
}