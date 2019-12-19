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

int		colour(t_matrix fir, t_matrix sec)
{
	return (0xffffff);
}
/*
**X=xcos(θ)+ysin(θ)
**Y=−xsin(θ)+ycos(θ)
*/
void	rotation(t_fdf *fdf, int i)
{
	double		tempx;
	double		tempy;

	tempx = (fdf->matrix[i].x - fdf->matrix[fdf->center].x) * fdf->pad;
	tempy = (fdf->matrix[i].y - fdf->matrix[fdf->center].y) * fdf->pad;
	fdf->matrix[i].sx = tempx * cos(fdf->sinrot) + tempy * sin(fdf->sinrot);
	fdf->matrix[i].sy = -tempx * sin(fdf->sinrot) + tempy * cos(fdf->sinrot);
	//printf("Angle:%f X%d Y%d to SY%d SX%d\n", fdf->sinrot,fdf->matrix[i].x, fdf->matrix[i].y, fdf->matrix[i].sx, fdf->matrix[i].sy);
	//printf("Relative pos X%f Y%f\n", tempx, tempy);
	//fdf->matrix[i].sx = 
}

void	vectorize(t_matrix fir, t_matrix sec, t_fdf *fdf, int bad)
{
	double	deltax;
	double	deltay;
	double	temp;
	int		mult;

	mult = 0;
	deltax = fir.sx - sec.sx;
	deltay = fir.sy - sec.sy;
	temp = (fabs(deltax) > fabs(deltay) ? deltax : deltay);
	deltax /= temp;
	deltay /= temp;
	printf("Vectors X %d to %d Y %d to %d\nDeltas: %f - %f\n", fir.sx, sec.sx, fir.sy, sec.sy, deltax, deltay);
	while (mult < fdf->pad)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->posx + sec.sx + (deltax * mult),
				fdf->posy + sec.sy + (deltax * mult), bad);
		//POSITION CALCULATION: fdf->posx + (sec.x * fdf->pad) + (deltax * mult)
		printf("Pixel put X%f Y%f\n*******\n", fdf->posx + sec.sx + (deltax * mult), fdf->posy + sec.sx + (deltay * mult));
		mult++;
	}
}

void	draw_image(t_fdf *fdf, int c)
{
	int		i;

	i = 0;
	while (i < fdf->height * fdf->width)
	{
		rotation(fdf, i);
		c = fdf->matrix[i].left;
		if (c != -1)
			vectorize(fdf->matrix[i], fdf->matrix[c], fdf, 0xffffff);
		c = fdf->matrix[i].up;
		if (c != -1)
			vectorize(fdf->matrix[i], fdf->matrix[c], fdf, 0xff2119);
		i++;
	}
}