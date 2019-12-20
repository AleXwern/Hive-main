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

int		mouse_main(int key, int x, int y, t_fdf *fdf)
{
	return (0);
}

int		key_main(int key, t_fdf *fdf)
{
	printf("Koy: %d\n", key);
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
	if (key == ROTLF)
		fdf->rlsin -= 5;
	if (key == ROTRL)
		fdf->rlsin += 5;
	if (key == ROTUP)
		fdf->rlflt -= 5;
	if (key == ROTDW)
		fdf->rlflt += 5;
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT || key == ROTDW || key == ROTLF || key == ROTUP || key == ROTRL)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		draw_image(fdf, 0);
	}
	return (0);
}