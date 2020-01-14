/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:52:31 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/14 17:28:01 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	set_complex(double rn, double in)
{
	t_complex	cn;

	cn.re = rn;
	cn.im = in;
	return (cn);
}

t_image		*init_image(t_fractol *frc)
{
	t_image		*img;

	if (!(img = (t_image*)malloc(sizeof(t_image))))
		error_out(MEM_ERROR, frc);
	if (!(img->img = mlx_new_image(frc->mlx, WINX, WINY)))
		error_out(IMG_ERROR, frc);
	img->data = mlx_get_data_addr(img->img, &(img->bpp), &(img->sizel),
			&(img->endn));
	return (img);
}

void		set_pixel(t_fractol *frc, int x, int y)
{

}

void		testdraw(t_fractol *frc)
{
	int		y;
	int		x;

	y = 0;
	while (y < WINY)
	{
		x = 0;
		frc->c.im = frc->max.im - (y * frc->factor.im);
		while (x < WINX)
		{
			frc->c.re = frc->min.re - (x * frc->factor.re);
			set_pixel(frc, x, y);
			x++;
		}
		y++;
	}
}

void		fractol_main(t_fractol *frc)
{
	frc->min = set_complex(-2.0, -2.0);
	frc->max.re = 2.0;
	frc->max.im = frc->min.im + (frc->max.re - frc->min.re) * ((double)WINY / (double)WINX);
	frc->factor = set_complex((frc->max.re - frc->min.re) / (WINX - 1),
			(frc->max.im - frc->min.im) / (WINY - 1));
	frc->color = color_set(0, frc->color);
	frc->zoom = 1.0;
	frc->iter = 100;
	testdraw(frc);
	mlx_key_hook(frc->win, key_main, frc);
	mlx_hook(frc->win, 6, 0, julia_move, frc);
	mlx_mouse_hook(frc->win, mouse_main, frc);
	mlx_loop(frc->mlx);
}