/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:52:31 by anystrom          #+#    #+#             */
/*   Updated: 2020/02/03 11:24:09 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <pthread.h>
#include <stdio.h>

/*
** Creates and sets DOUBLE values into complex number presentation.
*/

t_complex		set_complex(double rn, double in)
{
	t_complex	cn;

	cn.re = rn;
	cn.im = in;
	return (cn);
}

/*
** I determines a current XY position since DATA is 1D array.
** Gets color palette based on iteration and sets the palette into pixel.
*/

static void		set_pixel(t_fractol *frc, int x, int y)
{
	int			i;

	i = (x * frc->img->bpp / 8) + (y * frc->img->sizel);
	frc->color = get_color(define_set(frc), frc);
	*(int *)(frc->img->data + i) = frc->color.one;
	*(int *)(frc->img->data + (i + 1)) = frc->color.two;
	*(int *)(frc->img->data + (i + 2)) = frc->color.three;
	*(int *)(frc->img->data + (i + 3)) = frc->color.four;
}

/*
** Bread and butter fratal calculation.
** First sets a set FACTOR which is then used to calculate
** C with every single pixel that is analyzed (aka all 1M in 1000x1000)
*/

static void		frc_draw(t_fractol *frc)
{
	int			x;

	frc->factor = set_complex((frc->max.re - frc->min.re) / WINX,
			(frc->max.im - frc->min.im) / WINY);
	while (frc->start < WINY)
	{
		x = 0;
		frc->c.im = frc->max.im - frc->start * frc->factor.im;
		while (x < WINX)
		{
			frc->c.re = frc->min.re + x * frc->factor.re;
			set_pixel(frc, x, frc->start);
			x++;
		}
		frc->start += frc->threads;
	}
}

/*
** Heart of the system.
** PTHREAD is a bonus.
** makes X amount of threads and copies of FRC, set's an area they are
** responsible for.
** THREAD and FRAC are malloced and then freed after everything is done.
** Malloc was the easiest way of doing this since thread amount was
** to be made modifiedable.
*/

void			thread_core(t_fractol *frc)
{
	pthread_t	*thread;
	t_fractol	*frac;
	int			i;

	i = 0;
	thread = (pthread_t*)malloc(sizeof(pthread_t) * frc->threads);
	frac = (t_fractol*)malloc(sizeof(t_fractol) * frc->threads);
	while (i < frc->threads)
	{
		frac[i] = *frc;
		frac[i].start = i;
		if (pthread_create(&thread[i], NULL, (void *(*)(void *))frc_draw,
				(void*)&frac[i]))
			error_out(T_ERROR, frc);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(thread[i], NULL))
			error_out(T_ERROR, frc);
	free(thread);
	free(frac);
	mlx_put_image_to_window(frc->mlx, frc->win, frc->img->img, 0, 0);
	help_window(frc);
}

/*
** Readies input methods, gets and sets the image trough thread_core and
** then shows the image in window.
*/

void			fractol_main(t_fractol *frc)
{
	set_default(frc);
	mlx_key_hook(frc->win, key_main, frc);
	mlx_hook(frc->win, 6, 0, julia_move, frc);
	mlx_mouse_hook(frc->win, mouse_main, frc);
	thread_core(frc);
	mlx_loop(frc->mlx);
}
