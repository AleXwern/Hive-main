/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:13:55 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/01 15:20:10 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	vectorize(int px, int py, int x, int y, t_fdf *fdf)
{
	double	deltax;
	double	deltay;
	double	temp;
	int		mult;

	mult = 0;
	deltax = px - x;
	deltay = py - y;
	temp = (deltax > deltay ? deltax : deltay);
	deltax /= temp;
	deltay /= temp;
	while (deltax * mult != temp && deltay * mult != temp)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x + (deltax * mult), y + (deltay * mult), 0xffffff);
		mult++;
	}
}

int		ft_mouse(int key, int x, int y, t_fdf *fdf)
{
	static int	px;
	static int	py;

	vectorize(x, y, px, py, fdf);
	printf("X: %d, Y: %d Key: %d\n", x, y, key);
	px = x;
	py = y;
	return (0);
}

int		ft_btw(int key, t_fdf *fdf)
{
	static int	x;
	static int	y;
	int			i;

	i = 0;
	if (key == 7)
		exit (0);
	if (key == 123)
	{
		while (i < 10)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0x9900FF);
			x--;
			i++;
		}
	}
	if (key == 126)
	{
		while (i < 10)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0x9900FF);
			y--;
			i++;
		}
	}
	if (key == 124)
	{
		while (i < 10)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0x9900FF);
			x++;
			i++;
		}
	}
	if (key == 125)
	{
		while (i < 10)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0x9900FF);
			y++;
			i++;
		}
	}
	mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF);
	printf("X: %d Y: %d Key: %d\n", x, y, key);
	return (0);
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;
	int		rgb;
	int		x;
	int		y;

	x = 20;
	y = 20;
	rgb = 0x010101;
	fdf = (t_fdf*)malloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WINX, WINY, "This is text");
	while (y < 699)
	{
		rgb = rgb + 2;
		while (x < 699)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, rgb);
			x++;
			rgb += 0x000001;
		}
		rgb = rgb + 0x000100;
		if (rgb >= 0x000f00)
			rgb += 0x010000;
		x = 20;
		y++;
	}
	mlx_key_hook(fdf->win, ft_btw, fdf);
	mlx_mouse_hook(fdf->win, ft_mouse, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}