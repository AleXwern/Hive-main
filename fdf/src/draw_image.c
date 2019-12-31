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

int		colour(t_matrix fir, t_matrix sec, int top)
{
	int		z;

	z = (abs(fir.z) >= abs(sec.z) ? fir.z : sec.z);
	if (z == 0)
		return (0xFFFFFF);
	if (z < 0)
		return (0x87CEFA);
	if (z <= ((double)top / 5.0))
		return (0x03ff03);
	if (z <= ((double)top * (2.0 / 5.0)))
		return (0x28992d);
	if (z <= ((double)top * (3.0 / 5.0)))
		return (0xc27604);
	if (z <= ((double)top * (4.0 / 5.0)))
		return (0x946205);
	return (0xb50c04);
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

void	vectorize(t_matrix fir, t_matrix sec, t_fdf *fdf, int colour)
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
	while (mult <= fdf->pad * fabs(temp) * 20 && deltax * mult != temp &&
			deltay * mult != temp)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->posx + sec.sx + (deltax * mult),
				fdf->posy + sec.sy + (deltay * mult), colour);
		mult++;
	}
}

void	draw_image(t_fdf *fdf, int c)
{
	int		i;

	i = 0;
	while (i < fdf->mallocht * fdf->width)
	{
		rotation(fdf, i);
		c = fdf->matrix[i].left;
		if (c != -1)
			vectorize(fdf->matrix[i], fdf->matrix[c], fdf,
					colour(fdf->matrix[i], fdf->matrix[c], fdf->top));
		c = fdf->matrix[i].up;
		if (c != -1)
			vectorize(fdf->matrix[i], fdf->matrix[c], fdf,
					colour(fdf->matrix[i], fdf->matrix[c], fdf->top));
		c = fdf->matrix[i].top;
		if (c != -1)
			vectorize(fdf->matrix[i], fdf->matrix[c], fdf,
					colour(fdf->matrix[i], fdf->matrix[c], fdf->top));
		i++;
	}
}
