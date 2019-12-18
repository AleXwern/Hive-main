/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:13:55 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/01 15:20:10 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	vectorize(t_matrix fir, t_matrix sec, t_fdf *fdf, int bad)
{
	double	deltax;
	double	deltay;
	double	temp;
	int		mult;

	mult = 0;
	deltax = (fir.x * fdf->pad) - (sec.x * fdf->pad);
	deltay = (fir.y * fdf->pad) - (sec.y * fdf->pad);
	temp = (deltax > deltay ? deltax : deltay);
	deltax /= temp;
	deltay /= temp;
	//printf("**FIR X%d Y%d\n", fir.x, fir.y);
	//printf("**SEC X%d Y%d\n", sec.x, sec.y);
	//printf("Pad %d", fdf->pad);
	while (bad < fdf->pad)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->posx + (deltax * mult), fdf->posy + (deltay * mult), 0xffffff);
		//printf("Pixel put X%f Y%f\n", fdf->posx + (deltax * mult), fdf->posy + (deltay * mult));
		mult++;
		bad++;
	}
}

void	draw_image(t_fdf *fdf, int c)
{
	int		i;

	i = 1;
	while (i < fdf->height * fdf->width)
	{
		c = fdf->matrix[i].left;
		if (c != -1)
			vectorize(fdf->matrix[i], fdf->matrix[c], fdf, 0);
		c = fdf->matrix[i].up;
		if (c != -1)
			vectorize(fdf->matrix[i], fdf->matrix[c], fdf, 0);
		i++;
	}
}