/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:24:04 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/13 15:16:46 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_color		color_set(int set, t_color color)
{
	if (set > 2)
		set = 0;
	color.set = set;
	if (set == 0)
	{
		color.one = BLUE_ONE;
		color.two = BLUE_TWO;
		color.three = BLUE_THREE;
		color.four = BLUE_FOUR;
	}
	else if (set == 1)
	{
		color.one = BW_ONE;
		color.two = BW_TWO;
		color.three = BW_THREE;
		color.four = BW_FOUR;
	}
	else
	{
		color.one = PSY_ONE;
		color.two = PSY_TWO;
		color.three = PSY_THREE;
		color.four = PSY_FOUR;
	}
	return (color);
}