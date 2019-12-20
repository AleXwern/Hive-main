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
	int		colour;

	colour = 0x888888;
	if (fir.z > sec.z)
	{
		colour -= fir.z * 30 * 256;
		colour -= fir.z * 30;
	}
	else
	{
		colour -= sec.z * 30 * 256;
		colour -= sec.z * 30;
	}
	return (colour);
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

void	pixel_pos(t_fdf *fdf, t_matrix fir, t_matrix sec)
{
	if (fir.sx - sec.sx <= 0 && fir.sy - sec.sy <= 0)
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->posx + sec.sx + (fdf->deltax *
				fdf->mult), fdf->posy + sec.sy + (fdf->deltay * fdf->mult),
				colour(fir, sec));
	else if (fir.sx - sec.sx > 0 && fir.sx - sec.sx <= 0)
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->posx + fir.sx + (fdf->deltax *
				fdf->mult), fdf->posy + sec.sy + (fdf->deltay * fdf->mult),
				colour(fir, sec));
	else if (fir.sx - sec.sx <= 0 && fir.sx - sec.sx > 0)
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->posx + sec.sx + (fdf->deltax *
				fdf->mult), fdf->posy + fir.sy - (fdf->deltay * fdf->mult),
				colour(fir, sec));
	else
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->posx + fir.sx + (fdf->deltax *
				fdf->mult), fdf->posy + fir.sy + (fdf->deltay * fdf->mult),
				colour(fir, sec));
}

//putpix(fdf, fir, sec, deltax)
//putpiy(fdf, fir, sec, deltay)

void	vectorize(t_matrix fir, t_matrix sec, t_fdf *fdf, int color)
{
	double	temp;

	fdf->mult = 0;
	fdf->deltax = fir.sx - sec.sx;
	fdf->deltay = fir.sy - sec.sy;
	temp = (fabs(fdf->deltax) > fabs(fdf->deltay) ? fdf->deltax : fdf->deltay);
	fdf->deltax /= temp;
	fdf->deltay /= temp;
	while (fdf->mult <= fdf->pad * 2 && fdf->deltax * fdf->mult != temp && fdf->deltay * fdf->mult != temp)
	{
		pixel_pos(fdf, fir, sec);
		//if (fir.sx - sec.sx < 0 || fir.sy - sec.sy < 0)
		//	mlx_pixel_put(fdf->mlx, fdf->win, fdf->posx + fir.sx + (deltax * fdf->mult),
		//		fdf->posy + fir.sy + (deltay * fdf->mult), colour(fir, sec));
		//else
		//	mlx_pixel_put(fdf->mlx, fdf->win, fdf->posx + sec.sx + (deltax * fdf->mult),
		//		fdf->posy + sec.sy + (deltay * fdf->mult), colour(fir, sec));
		//printf("Hell oworld\n");
		fdf->mult++;
	}
}

void	draw_image(t_fdf *fdf, int c)
{
	int		i;

	i = 0;
	while (i < fdf->height * fdf->width && fdf->matrix[i].x != -1)
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