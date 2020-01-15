/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:52:04 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/15 16:37:44 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

int		key_main(int key, t_fractol *frc)
{
	if (key == ESC)
		error_out(FINE, frc);
	else if (key == SCR_UPH)
		frc->ishelp = (frc->ishelp * frc->ishelp) - 1;
	else if (key == SPACE)
		frc->fixjulia = (frc->fixjulia * frc->fixjulia) - 1;
	else if (key == UP)
		frc->sy -= WINX / 30;
	else if (key == DOWN)
		frc->sy += WINX / 30;
	else if (key == LEFT)
		frc->sx -= WINX / 30;
	else if (key == RIGHT)
		frc->sx += WINX / 30;
	testdraw(frc, 0);
	return (0);
}

int		mouse_main(int key, int x, int y, t_fractol *frc)
{
	printf("Key:%d at X%d Y%d\n", key, x, y);
	if (key == ESC)
		error_out(FINE, frc);
	return (0);
}

int		julia_move(int x, int y, t_fractol *frc)
{
	if (frc->fixjulia && frc->fractol == 1)
	{
		frc->jul = set_complex(
			((double)x / WINX - 0.5),
			((double)(WINY - y) / WINY - 0.5));
		testdraw(frc, 1);
	}
	return (0);
}