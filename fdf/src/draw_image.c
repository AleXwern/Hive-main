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
	int		base;
	int		temp;

	base = 0xffffff;
	temp = (fir.z >= sec.z ? fir.z * 2 : sec.z * 2);
	if (temp < 0)
		return (0xa6deff);
	if (temp == 0)
		temp++;
	while (abs(temp) > 0)
	{
		base -= 0x02080f;
		temp -= (abs(temp) / temp);
	}
	return (base);
}

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
	fdf->matrix[i].sy = fdf->matrix[i].sy * cos(fdf->fltrot) + (fdf->matrix[i].z
			* fdf->pad * sin(fdf->fltrot));
}

void	vectorize(t_matrix fir, t_matrix sec, t_fdf *fdf)
{
	double	deltax;
	double	deltay;
	double	temp;
	int		mult;

	mult = 0;
	deltax = fir.sx - sec.sx;
	deltay = fir.sy - sec.sy;
	temp = (fabs(deltax) > fabs(deltay) ? deltax : deltay);
	deltax /= fabs(temp);
	deltay /= fabs(temp);
	while (mult <= fdf->pad * 20 && deltax * mult != temp &&
			deltay * mult != temp)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->posx + sec.sx + (deltax * mult),
				fdf->posy + sec.sy + (deltay * mult), colour(fir, sec));
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
			vectorize(fdf->matrix[i], fdf->matrix[c], fdf);
		c = fdf->matrix[i].up;
		if (c != -1)
			vectorize(fdf->matrix[i], fdf->matrix[c], fdf);
		i++;
	}
}
