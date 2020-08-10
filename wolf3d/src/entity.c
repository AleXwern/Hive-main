/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:28:23 by anystrom          #+#    #+#             */
/*   Updated: 2020/08/10 13:21:39 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

t_chara	generate_foe(t_wolf *wlf)
{
	int		rand;
	t_chara	foe;

	rand = (int)wlf->rng % 8;
	if (rand == 0)
		foe.gfxid = 10;
	else
		foe.gfxid = 14 + rand;
	foe.name = "Beast";
	foe.maxhp = 450 + ((int)wlf->rng % 50 - 25) + (rand * 10);
	foe.hp = foe.maxhp;
	foe.row = 1;
	foe.action = 0;
	foe.defend = 2;
	return (foe);
}

t_chara	set_chara(char *setname, int setmaxhp, int setrow)
{
	t_chara		chara;

	chara.name = setname;
	chara.maxhp = setmaxhp;
	chara.hp = setmaxhp;
	chara.row = setrow;
	chara.action = 0;
	chara.defend = 2;
	chara.row = 2;
	return (chara);
}

t_chara	*generate_party(t_wolf *wlf)
{
	t_chara		*party;

	if (!(party = (t_chara*)malloc(sizeof(t_chara) * 6)))
		error_out(MEM_ERROR, wlf, 0);
	party[0] = set_chara("Aly", 250, 2);
	party[1] = set_chara("AleXwern", 250, 2);
	party[2] = set_chara("Aapeli", 250, 2);
	party[3] = set_chara("Skellu", 250, 1);
	party[4] = set_chara("Brute Justice", 250, 1);
	party[5] = generate_foe(wlf);
	return (party);
}

void	comp_foe(t_wolf *wlf, char *bpath, int i)
{
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin("gfx/foe/", "foe0.xpm"), 564, 396);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin("gfx/foe/", "foe1.xpm"), 564, 396);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin("gfx/foe/", "foe2.xpm"), 564, 396);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin("gfx/foe/", "foe4.xpm"), 564, 396);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin("gfx/foe/", "foe5.xpm"), 564, 396);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin("gfx/foe/", "foe6.xpm"), 564, 396);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin("gfx/foe/", "foe7.xpm"), 564, 396);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin("gfx/foe/", "foe8.xpm"), 564, 396);
	free(bpath);
	wlf->gfxcount = i;
	if (i != GFXCOUNT)
		error_out(GFX_ERROR, wlf, 0);
}
