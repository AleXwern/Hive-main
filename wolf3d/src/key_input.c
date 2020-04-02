/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:07:30 by anystrom          #+#    #+#             */
/*   Updated: 2020/04/02 14:03:56 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/value.h"
#include "../includes/wolf.h"

int				key_press(int key, t_wolf *wlf)
{
	ft_putnbr(key);
	ft_putendl(" ");
	if (key == KEY_T && wlf->aggro > 500)
	{
		wlf->aggro = 0;
		wlf->cycle = &render;
		return (0);
	}
	if (key == ESC)
		error_out(FINE, wlf);
	if (key == LEFT || key == RIGHT)
		move_lr(key, wlf);
	if (key == UP || key == DOWN)
		move_fb(key, wlf);
	if (key == KEY_T)
		wlf->texbool = (wlf->texbool * wlf->texbool) - 1;
	if (key == SPACE)
		interact(wlf);
	return (0);
}

int				key_release(int key, t_wolf *wlf)
{
	return (0);
}

int				x_press(t_wolf *wolf)
{
	error_out(FINE, wolf);
	return (0);
}
