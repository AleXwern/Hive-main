/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mou_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:52:04 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/22 16:29:59 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	zoom(int key, t_fractol *frc, t_complex mpos)
{
	if (key == SCR_UPH)
		frc->zoom = 1.0 * 0.9;
	if (key == SCR_DOWN)
		frc->zoom = 1.0 / 0.9;
	frc->min.re = ((frc->min.re - mpos.re) * frc->zoom) + mpos.re;
	frc->min.im = ((frc->min.im - mpos.im) * frc->zoom) + mpos.im;
	frc->max.re = ((frc->max.re - mpos.re) * frc->zoom) + mpos.re;
	frc->max.im = ((frc->max.im - mpos.im) * frc->zoom) + mpos.im;
}

int			mouse_main(int key, int x, int y, t_fractol *frc)
{
	t_complex	mpos;

	mpos.re = 1.00 * x / (WINX / (frc->max.re - frc->min.re)) + frc->min.re;
	mpos.im = -1.0 * y / (WINY / (frc->max.im - frc->min.im)) + frc->max.im;
	if (key == SCR_DOWN || key == SCR_UPH)
		zoom(key, frc, mpos);
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
