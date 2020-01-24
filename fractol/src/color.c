/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:24:04 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/24 14:27:21 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Color stuff
** Function is spread to four parts
** A * B * C * D
** Basically B and C are the most important factors.
** Rising pow(t) power makes the graph lean on right.
** Likewise pow(1 - t) has the opposite effect.
** 0-point of X+1 is half of X, where X is power.
** Removing B or C or setting power as 0 is the key to filling valid area.
*/

static t_color	color_set(int set, double t, t_color color)
{
	if (set > 2)
		set = 0;
	color.set = set;
	if (set == 0)
	{
		color.one = (12 * pow((1 - t), 0) * pow(t, 3) * 255);
		color.two = (13 * pow((1 - t), 2) * pow(t, 2) * 255);
		color.three = (14 * pow((1 - t), 2) * pow(t, 1) * 255);
		color.four = (16 * pow((1 - t), 3) * pow(t, 0) * 255);
	}
	else if (set == 1)
	{
		color.one = (16 * pow((1 - t), 2) * pow(t, 2) * 240);
		color.two = (16 * pow((1 - t), 2) * pow(t, 2) * 240);
		color.three = (16 * pow((1 - t), 2) * pow(t, 2) * 240);
		color.four = (13 * pow((1 - t), 3) * pow(t, 1) * 64);
	}
	else
	{
		color.one = (16 * pow((1 - t), 1) * 255);
		color.two = (16 * pow((1 - t), 4) + pow(t, 1) * 255);
		color.three = (16 * pow((1 - t), 4) + pow(t, 1) * 255);
		color.four = (16 * pow((1 - t), 4) * pow(t, 1) * 140);
	}
	return (color);
}

/*
** Creates, sets and returns a color palette based on ITER
** T is a double value between 0 and 1.
*/

t_color			get_color(int iter, t_fractol *frc)
{
	t_color		color;
	double		t;

	t = (double)iter / frc->iter;
	color = color_set(frc->color.set, t, frc->color);
	return (color);
}
