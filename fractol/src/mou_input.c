/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mou_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:52:04 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/17 17:50:19 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

static void	zoom(int key, double y, double x, t_fractol *frc)
{
	static int	power;

	if (key == SCR_UPH)
		power--;
	if (key == SCR_DOWN)
		power++;
	frc->zoom = pow(1.01, (double)power);
	frc->min.re *= frc->zoom;
	frc->min.im *= frc->zoom;
	frc->max.re *= frc->zoom;
	frc->max.im *= frc->zoom;
	frc->min.re += x;
	frc->min.im -= y;
	frc->max.re += x;
	frc->max.im -= y;
}

int		mouse_main(int key, int x, int y, t_fractol *frc)
{
	double	ydelta;
	double	xdelta;

	xdelta = 0.5 * ((double)x / WINX - 0.5);
	ydelta = 0.5 * ((double)y / WINY - 0.5);
	printf("Key:%d at X%d Y%d\n", key, x, y);
	if (key == SCR_DOWN || key == SCR_UPH)
		zoom(key, ydelta, xdelta, frc);
	mlx_clear_window(frc->mlx, frc->win);
	thread_core(frc);
	return (0);
}

int		julia_move(int x, int y, t_fractol *frc)
{
	if (frc->fixjulia && frc->fractol == 1)
	{
		frc->jul = set_complex(4 * ((double)x / WINX - 0.5),
			4 * ((double)(WINY - y) / WINY - 0.5));
		mlx_clear_window(frc->mlx, frc->win);
		thread_core(frc);
	}
	return (0);
}