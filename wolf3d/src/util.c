/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:28:33 by anystrom          #+#    #+#             */
/*   Updated: 2020/06/15 14:01:55 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	free_memory(char **arr)
{
	int y;

	y = 0;
	while (arr[y])
		y++;
	while (y >= 0)
		ft_strdel(&arr[y--]);
	free(arr);
	arr = NULL;
}

int		arr_len(char **arr)
{
	int		i;

	i = 0;
	while (arr[i][0] != '\0')
		i++;
	return (i);
}

void	free_layer(t_wolf *wlf, int f, int y, int mxy)
{
	wlf->mxflr = f - 1;
	while (++y < mxy)
	{
		if (wlf->map[f][y])
			free(wlf->map[f][y]);
	}
	if (wlf->map[f])
		free(wlf->map[f]);
}

void	free_map(t_wolf *wlf, int f, int y)
{
	while (++f < wlf->mxflr)
	{
		y = -1;
		while (++y < wlf->height)
		{
			if (wlf->map[f][y])
				free(wlf->map[f][y]);
		}
		if (wlf->map[f])
			free(wlf->map[f]);
	}
}

void	exit_combat(t_wolf *wlf)
{
	wlf->plr = 0;
	wlf->sel = -1;
	wlf->cur = 0;
	wlf->aggro = 0;
	wlf->cycle = &render;
	wlf->keyup = 0;
	wlf->keydown = 0;
	wlf->keyright = 0;
	wlf->keyleft = 0;
	wlf->chara[5] = generate_foe(wlf);
	health_check(wlf, -1, 0);
	wlf->plr--;
	wlf->plrck = wlf->plr + 1;
	if (wlf->plrck < 0)
	{
		wlf->plr++;
		wlf->plrck++;
	}
	free(wlf->syssmg[0]);
	free(wlf->syssmg[1]);
	wlf->syssmg[0] = ft_strdup("You encountered a strong beast!");
	wlf->syssmg[1] = ft_strdup("What will you do?");
}
