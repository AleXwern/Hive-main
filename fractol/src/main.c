/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:18:02 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/08 16:59:51 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	error_out(char *msg, t_fractol *frc)
{
	ft_putendl(msg);
	if (frc->img.img)
		mlx_destroy_image(frc->mlx, frc->img.img);
	if (frc->winbool == 1)
		mlx_destroy_window(frc->mlx, frc->win);
	exit(0);
}

void	define_fratol(t_fractol *frc, char **av)
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

int		main(int ac, char **av)
{
	t_fractol	*frc;

	if (!(frc = (t_fractol*)malloc(sizeof(t_fractol))))
		error_out(MEM_ERROR, frc);
	if (ac != 2)
		error_out(USAGE, frc);
	define_fratol(frc, av);
	frc->mlx = mlx_init();
	frc->win = mlx_new_window(frc->mlx, WINX, WINY, ft_strjoin("Fractol ", av[1]));
	mlx_key_hook(frc->win, key_main, frc);
	//mlx_mouse_hook();
	mlx_loop(frc->mlx);
	return (0);
} 
