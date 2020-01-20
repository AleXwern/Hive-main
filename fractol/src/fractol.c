/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:52:31 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/20 16:28:34 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <pthread.h>

t_complex		set_complex(double rn, double in)
{
	t_complex	cn;

	cn.re = rn;
	cn.im = in;
	return (cn);
}

static void		set_pixel(t_fractol *frc, int x, int y)
{
	int			i;

	i = (x * frc->img->bpp / 8) + (y * frc->img->sizel);
	frc->color = get_color(define_set(frc), frc);
	*(int *)(frc->img->data + i) = frc->color.one;
	*(int *)(frc->img->data + (++i)) = frc->color.two;
	*(int *)(frc->img->data + (++i)) = frc->color.three;
	*(int *)(frc->img->data + (++i)) = frc->color.four;
}

static void		frc_draw(t_fractol *frc)
{
	int			y;
	int			x;

	frc->factor = set_complex((frc->max.re - frc->min.re) / (WINX - 1),
			(frc->max.im - frc->min.im) / (WINY - 1));
	y = frc->start;
	while (y < frc->end)
	{
		x = 0;
		frc->c.im = frc->max.im - y * frc->factor.im;
		while (x < WINX)
		{
			frc->c.re = frc->min.re + x * frc->factor.re;
			set_pixel(frc, x, y);
			x++;
		}
		y++;
	}
}

void			thread_core(t_fractol *frc)
{
	pthread_t	thread[frc->threads];
	t_fractol	frac[frc->threads];
	int			i;

	i = 0;
	while (i < frc->threads)
	{
		frac[i] = *frc;
		frac[i].start = i * (WINY / frc->threads);
		frac[i].end = (i + 1) * (WINY / frc->threads);
		if (pthread_create(&thread[i], NULL, (void *(*)(void *))frc_draw,
				(void*)&frac[i]))
			error_out(T_ERROR, frc);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(thread[i], NULL))
			error_out(T_ERROR, frc);
	mlx_put_image_to_window(frc->mlx, frc->win, frc->img->img, 0, 0);
	help_window(frc);
}

void			fractol_main(t_fractol *frc)
{
	set_default(frc);
	mlx_key_hook(frc->win, key_main, frc);
	mlx_hook(frc->win, 6, 0, julia_move, frc);
	mlx_mouse_hook(frc->win, mouse_main, frc);
	thread_core(frc);
	mlx_loop(frc->mlx);
}
