/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:24:04 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:47 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_color	get_color(int iter, t_fractol *frc)
{
	t_color		color;
	double		t;

	t = (double)iter / frc->iter;
	color = color_set(frc->color.set, t, frc->color);
	return (color);
}

t_color		color_set(int set, double t, t_color color)
{
	if (set > 2)
		set = 0;
	color.set = set;
	if (set == 0)
	{
		color.one = (9 * pow((1 - t), 0) * pow(t, 3) * 255);
		color.two = (13 * pow((1 - t), 1) * pow(t, 2) * 255);
		color.three = (17 * pow((1 - t), 2) * pow(t, 1) * 255);
		color.four = (20 * pow((1 - t), 3) * pow(t, 0) * 255);
	}
	else if (set == 1)
	{
		color.one = (11 * pow((1 - t), 0) * pow(t, 3) * 255);
		color.two = (15 * pow((1 - t), 1) * pow(t, 2) * 255);
		color.three = (19 * pow((1 - t), 2) * pow(t, 1) * 255);
		color.four = (22 * pow((1 - t), 3) * pow(t, 0) * 255);
	}
	else
	{
		color.one = (30 * pow((1 - t), 1) * pow(t, 4) * 255);
		color.two = (30 * pow((1 - t), 2) * pow(t, 3) * 255);
		color.three = (30 * pow((1 - t), 3) * pow(t, 2) * 255);
		color.four = (30 * pow((1 - t), 4) * pow(t, 1) * 255);
	}
	return (color);
}