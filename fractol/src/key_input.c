/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:40:31 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/17 17:50:37 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	change_fractal(int key, t_fractol *frc)
{
	if (key == KEY_ONE)
		frc->fractol = 0;
	else if (key == KEY_TWO)
		frc->fractol = 1;
	else if (key == KEY_TRE)
		frc->fractol = 2;
	else if (key == KEY_C)
		frc->color.set++;
	else if (key == NUM_PLU)
		frc->iter++;
	else if (key == NUM_MIN)
		frc->iter--;
}

static void	arrow_key(int key, t_fractol *frc)
{
	t_complex	delta;

	delta = set_complex(frc->max.re - frc->min.re, frc->max.im - frc->min.im);
	if (key == UP)
	{
		frc->min.im += (delta.im * 0.05);
		frc->max.im += (delta.im * 0.05);
	}
	else if (key == DOWN)
	{
		frc->min.im -= (delta.im * 0.05);
		frc->max.im -= (delta.im * 0.05);
	}
	else if (key == LEFT)
	{
		frc->min.re -= (delta.im * 0.05);
		frc->max.re -= (delta.im * 0.05);
	}
	else if (key == RIGHT)
	{
		frc->min.re += (delta.im * 0.05);
		frc->max.re += (delta.im * 0.05);
	}
}

int		key_main(int key, t_fractol *frc)
{
	ft_putnbr(key);
	ft_putendl("");
	if (key == ESC)
		error_out(FINE, frc);
	else if (key == SCR_UPH)
		frc->ishelp = (frc->ishelp * frc->ishelp) - 1;
	else if (key == SPACE)
		frc->fixjulia = (frc->fixjulia * frc->fixjulia) - 1;
	else if (key == KEY_R)
		set_default(frc);
	else if (key >= 123 && key <= 126)
		arrow_key(key, frc);
	else if ((key >= 18 && key <= 20) || key == 8 || key == 69 || key == 78)
		change_fractal(key ,frc);
	mlx_clear_window(frc->mlx, frc->win);
	thread_core(frc);
	return (0);
}