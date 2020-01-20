/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:18:02 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/20 16:27:45 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_image	*init_image(t_fractol *frc)
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

void			set_default(t_fractol *frc)
{
	frc->min = set_complex(-2.0, -2.0);
	frc->max.re = 2.0;
	frc->max.im = frc->min.im + (frc->max.re - frc->min.re) *
			(double)WINY / (double)WINX;
	frc->jul = set_complex(-0.4, 0.6);
	frc->color.set = 0;
	frc->zoom = 1.0;
	frc->iter = 30;
}

void			error_out(char *msg, t_fractol *frc)
{
	ft_putendl(msg);
	if (frc->img)
		mlx_destroy_image(frc->mlx, frc->img->img);
	if (frc->winbool == 1)
		mlx_destroy_window(frc->mlx, frc->win);
	exit(0);
}

static void		define_fratol(t_fractol *frc, char **av)
{
	if (!ft_strcmp(av[1], "mandelbrot"))
		frc->fractol = 0;
	else if (!ft_strcmp(av[1], "julia"))
		frc->fractol = 1;
	else if (!ft_strcmp(av[1], "bship"))
		frc->fractol = 2;
	else
		error_out(B_ARG, frc);
}

int				main(int ac, char **av)
{
	t_fractol	*frc;

	if (!(frc = (t_fractol*)malloc(sizeof(t_fractol))))
		error_out(MEM_ERROR, frc);
	if (ac != 2)
		error_out(USAGE, frc);
	define_fratol(frc, av);
	if (!(frc->mlx = mlx_init()))
		error_out(MLX_ERROR, frc);
	if (!(frc->win = mlx_new_window(frc->mlx, WINX, WINY,
			"Fract'ol Render")))
		error_out(WIN_ERROR, frc);
	frc->winbool = 1;
	frc->img = init_image(frc);
	frc->threads = 8;
	fractol_main(frc);
	ft_putendl(OOPS);
	return (0);
}
