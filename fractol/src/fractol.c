/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:52:31 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/15 16:48:27 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//DELETE THIS
t_color	get_color(int iteration, t_fractol *frc)
{
	t_color	color;
	double	t;

	t = (double)iteration / frc->iter;
	color.one = 0;
	color.two = (9 * (1 - t) * pow(t, 3) * 255);
	color.three = (15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.four = (8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}

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
	int			i;
	t_complex	z;
	t_complex	ztwo;
	int			boolean;

	boolean = 1;
	z = set_complex(frc->c.re, frc->c.im);
	frc->color = get_color(define_set(frc), frc);
	*(int *)(frc->img->data + (x * frc->img->bpp / 8) + (y * frc->img->sizel)) = frc->color.one;
	*(int *)(frc->img->data + (x * frc->img->bpp / 8) + (y * frc->img->sizel) + 1) = frc->color.two;
	*(int *)(frc->img->data + (x * frc->img->bpp / 8) + (y * frc->img->sizel) + 2) = frc->color.three;
	*(int *)(frc->img->data + (x * frc->img->bpp / 8) + (y * frc->img->sizel) + 3) = frc->color.four;
}

void		testdraw(t_fractol *frc, int rd)
{
	int		y;
	int		x;

	y = 0;
	while (y < WINY && rd == 1)
	{
		x = 0;
		frc->c.im = frc->max.im - (y * frc->factor.im);
		while (x < WINX)
		{
			frc->c.re = frc->min.re + (x * frc->factor.re);
			set_pixel(frc, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frc->mlx, frc->win, frc->img->img, frc->sx, frc->sy);
	help_window(frc);
}

void		fractol_main(t_fractol *frc)
{
	frc->min = set_complex(-2.0, -2.0);
	frc->max.re = 2.0;
	frc->max.im = frc->min.im + ((frc->max.re - frc->min.re) * ((double)WINY / (double)WINX));
	frc->factor = set_complex((frc->max.re - frc->min.re) / (WINX - 1),
			(frc->max.im - frc->min.im) / (WINY - 1));
	frc->jul = set_complex(-0.4, 0.6);
	frc->color = color_set(0, frc->color);
	frc->zoom = 1.0;
	frc->iter = 40;
	frc->sx = 0;
	frc->sy = 0;
	mlx_key_hook(frc->win, key_main, frc);
	mlx_hook(frc->win, 6, 0, julia_move, frc);
	mlx_mouse_hook(frc->win, mouse_main, frc);
	testdraw(frc, 1);
	mlx_loop(frc->mlx);
}