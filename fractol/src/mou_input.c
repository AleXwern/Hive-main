/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mou_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:52:04 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/21 17:00:10 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	zoom(int key, t_fractol *frc)
{
	if (key == SCR_UPH)
		frc->zoom = 1.0 * 0.9;
	if (key == SCR_DOWN)
		frc->zoom = 1.0 / 0.9;
	frc->min.re *= frc->zoom;
	frc->min.im *= frc->zoom;
	frc->max.re *= frc->zoom;
	frc->max.im *= frc->zoom;
}

int			mouse_main(int key, int x, int y, t_fractol *frc)
{
	x = y;
	if (key == SCR_DOWN || key == SCR_UPH)
		zoom(key, frc);
	mlx_clear_window(frc->mlx, frc->win);
	thread_core(frc);
	return (0);
}

int			julia_move(int x, int y, t_fractol *frc)
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
