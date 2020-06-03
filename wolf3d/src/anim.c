/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 12:00:44 by anystrom          #+#    #+#             */
/*   Updated: 2020/06/03 15:44:32 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

char	*get_syssmgone(t_wolf *wlf, int pc)
{
	char	*temp;
	int		tar;

	tar = wlf->chara[pc].target;
	if (wlf->chara[pc].action == 1)
		temp = ft_quadjoin(wlf->chara[pc].name, HIT_OPP, wlf->chara[tar].name, "");
	else if (wlf->chara[pc].action == 2)
		temp = ft_quadjoin(wlf->chara[pc].name, HEAL_OPP, wlf->chara[wlf->chara[pc].target].name, "");
	else if (wlf->chara[pc].action == 3)
		temp = ft_quadjoin(wlf->chara[pc].name, CHA_OPP, wlf->chara[tar].name, "");
	else
		temp = ft_strjoin(wlf->chara[pc].name, DEF_OPP);
	return (temp);
}

char	*get_syssmgtwo(t_wolf *wlf, int pc)
{
	char	*temp;
	char	*ret;
	int		tar;

	tar = wlf->chara[pc].target;
	if (wlf->chara[pc].action == 1)
	{
		temp = ft_itoa(20 * wlf->chara[tar].row * wlf->chara[tar].defend + ((int)wlf->rng % 12 - 6));
		ret = ft_strjoin(LOST_HP, temp);
		free(temp);
	}
	else if (wlf->chara[pc].action == 2)
		ret = ft_strjoin(GET_HP, "15");
	else if (wlf->chara[pc].action == 3)
	{
		temp = ft_itoa(30 * wlf->chara[tar].row * wlf->chara[tar].defend + ((int)wlf->rng % 14 - 7));
		ret = ft_strjoin(LOST_HP, temp);
		free(temp);
	}
	else
		ret = ft_strjoin(wlf->chara[pc].name, DEF_HP);
	return (ret);
}

int		get_y(int pc)
{
	if (pc < 3)
		return (535);
	else
		return (634);
}

int		get_x(int pc)
{
	if (pc == 0)
		return (71);
	else if (pc == 1)
		return (429);
	else if (pc == 2)
		return (787);
	else if (pc == 3)
		return (250);
	else
		return (608);
}

void	place_pc(t_wolf *wlf, int frame, int pc)
{
	int		x;
	int		y;

	if (frame < 3)
		x = 0;
	else if (frame < 6)
		x = 1;
	else
		x = 2;
	y = frame % 3;
	while (pc < 5)
	{
		if (pc == wlf->plr)
			mlx_string_put(wlf->mlx, wlf->win, get_x(pc) + x, get_y(pc) + y, 0, wlf->chara[pc].name);
		else
			mlx_string_put(wlf->mlx, wlf->win, get_x(pc), get_y(pc), 0, wlf->chara[pc].name);
		pc++;
	}
}