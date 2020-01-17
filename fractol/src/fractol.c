/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:52:31 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/17 15:55:16 by anystrom         ###   ########.fr       */
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
	int			i;

	i = (x * frc->img->bpp / 8) + (y * frc->img->sizel);
	frc->color = get_color(define_set(frc), frc);
	*(int *)(frc->img->data + i) = frc->color.one;
	*(int *)(frc->img->data + (++i)) = frc->color.two;
	*(int *)(frc->img->data + (++i)) = frc->color.three;
	*(int *)(frc->img->data + (++i)) = frc->color.four;
}

void		testdraw(t_fractol *frc, int rd)
{
	int		y;
	int		x;

	frc->factor = set_complex((frc->max.re - frc->min.re) / (WINX - 1),
			(frc->max.im - frc->min.im) / (WINY - 1));
	y = 0;
	while (y < WINY && rd == 1)
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
	mlx_put_image_to_window(frc->mlx, frc->win, frc->img->img, 0, 0);
	help_window(frc);
}

void		fractol_main(t_fractol *frc)
{
	set_default(frc);
	mlx_key_hook(frc->win, key_main, frc);
	mlx_hook(frc->win, 6, 0, julia_move, frc);
	mlx_mouse_hook(frc->win, mouse_main, frc);
	testdraw(frc, 1);
	mlx_loop(frc->mlx);
}