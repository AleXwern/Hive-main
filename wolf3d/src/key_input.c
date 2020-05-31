/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:07:30 by anystrom          #+#    #+#             */
/*   Updated: 2020/05/28 00:38:04 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/value.h"
#include "../includes/wolf.h"

int				key_press(int key, t_wolf *wlf)
{
	//ft_putnbrln(key);
	if (key == ESC)
		error_out(FINE, wlf);
	else if (wlf->aggro > 500)
		combat_key(key, wlf);
	else if (key == LEFT || key == RIGHT)
		move_lr(key, wlf);
	else if (key == UP || key == DOWN)
		move_fb(key, wlf);
	else if (key == KEY_T)
		wlf->texbool = (wlf->texbool * wlf->texbool) - 1;
	else if (key == SPACE)
		interact(wlf);
	else if (key == KEY_C)
		wlf->aggro = 499;
	return (0);
}

int				key_hold(int key, t_wolf *wlf)
{
	if (wlf->aggro > 500 && wlf->isclick)
		combat_key(key, wlf);
	if (wlf->aggro > 500)
		return (0);
	if (key == ESC)
		error_out(FINE, wlf);
	if (key == LEFT)
		wlf->keyleft = 1;
	if (key == RIGHT)
		wlf->keyright = 1;
	if (key == UP)
		wlf->keyup = 1;
	if (key == DOWN)
		wlf->keydown = 1;
	if (key == KEY_T)
		wlf->keyt = 1;
	if (key == SPACE)
		wlf->keyspace = 1;
	if (key == KEY_C)
		wlf->keyc = 1;
	return (0);
}

int				key_release(int key, t_wolf *wlf)
{
	wlf->isclick = 1;
	if (key == LEFT)
		wlf->keyleft = 0;
	if (key == RIGHT)
		wlf->keyright = 0;
	if (key == UP)
		wlf->keyup = 0;
	if (key == DOWN)
		wlf->keydown = 0;
	if (key == KEY_T)
		wlf->keyt = 0;
	if (key == SPACE)
		wlf->keyspace = 0;
	if (key == KEY_C)
		wlf->keyc = 0;
	return (0);
}

int				x_press(t_wolf *wolf)
{
	error_out(FINE, wolf);
	return (0);
}
