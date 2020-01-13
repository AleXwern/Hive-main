/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:52:04 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/13 17:19:29 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

int		key_main(int key, t_fractol *frc)
{
	if (key == ESC)
		error_out(FINE, frc);
	if (key == SCR_UPH)
		frc->ishelp = (frc->ishelp * frc->ishelp) - 1;
	printf("%d\n", frc->ishelp);
	fractol_main(frc);
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
	//printf("X%d Y%d\n", x, y);
	if (x > 100000)
		error_out(FINE, frc);
	return (0);
}