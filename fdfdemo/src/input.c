/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:13:55 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/01 15:20:10 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		camera_main(int key, t_fdf *fdf)
{
	if (key == ROTLF)
		fdf->rlsin -= 5;
	if (key == ROTRL)
		fdf->rlsin += 5;
	if (key == ROTUP)
		fdf->rlflt -= 5;
	if (key == ROTDW)
		fdf->rlflt += 5;
	if (key == ZOOMI)
		fdf->pad++;
	if (key == ZOOMO)
	{
		fdf->pad--;
		if (fdf->pad == 0)
			fdf->pad = 1;
	}
	if (key == ROTLF || key == ROTRL || key == ROTUP || key == ROTDW || key == ZOOMI || key == ZOOMO)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		draw_image(fdf, 0);
	}
	return (0);
}

int		key_main(int key, t_fdf *fdf)
{
	//printf("Koy: %d\n", key);
	if (key == ESC)
		error_out(FINE, fdf);
	if (key == UP)
		fdf->posy -= 5;
	if (key == DOWN)
		fdf->posy += 5;
	if (key == LEFT)
		fdf->posx -= 5;
	if (key == RIGHT)
		fdf->posx += 5;
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		draw_image(fdf, 0);
	}
	else
		camera_main(key, fdf);
	return (0);
}