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

	fdf->sinrot = (fdf->rlsin * (M_PI / 180));
	fdf->fltrot = (fdf->rlflt * (M_PI / 180));
	tempx = (fdf->matrix[i].x - fdf->matrix[fdf->center].x) * fdf->pad;
	tempy = (fdf->matrix[i].y - fdf->matrix[fdf->center].y) * fdf->pad;
	fdf->matrix[i].sx = tempx * cos(fdf->sinrot) + tempy * sin(fdf->sinrot);
	fdf->matrix[i].sy = -tempx * sin(fdf->sinrot) + tempy * cos(fdf->sinrot);
	fdf->matrix[i].sy = fdf->matrix[i].sy * cos(fdf->fltrot) + (fdf->matrix[i].z * fdf->pad * sin(fdf->fltrot));
}

void	vectorize(t_matrix fir, t_matrix sec, t_fdf *fdf, int color)
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
	while (mult <= fdf->pad * 2 && deltax * mult != temp && deltay * mult != temp)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->posx + sec.sx + (deltax * mult),
				fdf->posy + sec.sy + (deltay * mult), color);
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
		{
			if (fdf->matrix[i].sx < fdf->matrix[c].sx)
				vectorize(fdf->matrix[c], fdf->matrix[i], fdf, 0xffffff);
			else
				vectorize(fdf->matrix[i], fdf->matrix[c], fdf, 0xff00ff);
		}
		c = fdf->matrix[i].up;
		if (c != -1)
		{
			if (fdf->matrix[i].sy < fdf->matrix[c].sy)
				vectorize(fdf->matrix[c], fdf->matrix[i], fdf, 0xffffff);
			else
				vectorize(fdf->matrix[i], fdf->matrix[c], fdf, 0xff00ff);
		}
		i++;
	}
}