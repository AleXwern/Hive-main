/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:38:13 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/10 15:23:16 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	wall_stripe(t_wolf *wlf)
{
	while (++wlf->start <= wlf->end)
	{
		ft_memcpy(wlf->img.data + 4 * WINX * wlf->start + wlf->x * 4,
				&wlf->testcolor, sizeof(int));
	}
}