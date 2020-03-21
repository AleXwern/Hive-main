/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JessicaNystrom <JessicaNystrom@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:07:30 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/15 12:42:39 by JessicaNyst      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/value.h"
#include "../includes/wolf.h"

int				key_press(int key, t_wolf *wlf)
{
	ft_putnbr(key);
	ft_putendl(" ");
	if (key == ESC)
		error_out(FINE, wlf);
	if (key == LEFT || key == RIGHT)
		move_lr(key, wlf);
	if (key == UP || key == DOWN)
		move_fb(key, wlf);
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