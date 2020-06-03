/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:28:23 by anystrom          #+#    #+#             */
/*   Updated: 2020/06/03 15:32:02 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

t_chara	generate_foe(t_wolf *wlf)
{
	int		rand;
	t_chara	foe;

	rand = (int)wlf->rng % 9;
	if (rand == 0)
		foe.gfxid = 10;
	else
		foe.gfxid = 10;
	foe.name = "Beast";
	foe.maxhp = 130 + ((int)wlf->rng % 20 - 10);
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
		error_out(MEM_ERROR, wlf);
	party[0] = set_chara("Aly", 250, 2);
	party[1] = set_chara("AleXwern", 250, 2);
	party[2] = set_chara("Aapeli", 250, 2);
	party[3] = set_chara("Skellu", 250, 1);
	party[4] = set_chara("Brute Justice", 250, 1);
	party[5] = generate_foe(wlf);
	return (party);
}
