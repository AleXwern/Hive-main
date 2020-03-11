/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:07:30 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/11 15:33:06 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/value.h"
#include "../includes/wolf.h"

int				key_press(int key, t_wolf *wlf)
{
	if (key == ESC)
		error_out(FINE, wlf);
	if (key == LEFT || key == RIGHT)
		move_lr(key, wlf);
	if (key == UP || key == DOWN)
		move_fb(key, wlf);
	if (key == KEY_C)
		wlf->fcomb = 1;
	else
		wlf->fcomb = 0;
	return (0);
}

int				key_release(int key, t_wolf *wlf)
{
	if (key == KEY_C)
		wlf->fcomb = (wlf->fcomb * wlf->fcomb) - 1;
	ft_putendl("A press\n");
	return (0);
}

int				x_press(t_wolf *wolf)
{
	error_out(FINE, wolf);
	return (0);
}
