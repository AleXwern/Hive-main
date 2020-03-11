/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:07:30 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/11 14:52:19 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/value.h"
#include "../includes/wolf.h"

int				key_press(int key, t_wolf *wolf)
{
	if (key == ESC)
		error_out(FINE, wolf);
	if (key == LEFT || key == RIGHT)
		move_lr(key, wolf);
	if (key == UP || key == DOWN)
		move_fb(key, wolf);
	return (0);
}

int				key_release(int key, t_wolf *wolf)
{
	wolf->hold = 0;
	ft_putendl("A press\n");
	return (0);
}

int				x_press(t_wolf *wolf)
{
	error_out(FINE, wolf);
	return (0);
}
