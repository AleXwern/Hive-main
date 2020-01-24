/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:41:36 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/24 14:27:25 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Determines what fractal is currently set and returns int ITER
** that is used to calculate color with frc_FRACTAL.
*/

static int	frc_tricorn(t_fractol *frc)
{
	int			iter;
	t_complex	z;

	z = set_complex(frc->c.re, frc->c.im);
	iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iter < frc->iter)
	{
		z = set_complex(
			-2.0 * z.im * z.re + frc->c.re,
			pow(z.im, 2.0) - pow(z.re, 2.0) + frc->c.im);
		iter++;
	}
	return (iter);
}

static int	frc_mandelbrot(t_fractol *frc)
{
	int			iter;
	t_complex	z;

	z = set_complex(frc->c.re, frc->c.im);
	iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iter < frc->iter)
	{
		z = set_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + frc->c.re,
			2.0 * z.re * z.im + frc->c.im);
		iter++;
	}
	return (iter);
}

static int	frc_bship(t_fractol *frc)
{
	int			iter;
	t_complex	z;

	z = set_complex(frc->c.re, frc->c.im);
	iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iter < frc->iter)
	{
		z = set_complex(
			fabs(pow(z.re, 2.0) - pow(z.im, 2.0) + frc->c.re),
			fabs(-2.0 * z.re * z.im + frc->c.im));
		iter++;
	}
	return (iter);
}

static int	frc_julia(t_fractol *frc)
{
	int			iter;
	t_complex	z;

	z = set_complex(frc->c.re, frc->c.im);
	iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iter < frc->iter)
	{
		z = set_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + frc->jul.re,
			2.0 * z.re * z.im + frc->jul.im);
		iter++;
	}
	return (iter);
}

int			define_set(t_fractol *frc)
{
	if (frc->fractol == 1)
		return (frc_julia(frc));
	else if (frc->fractol == 0)
		return (frc_mandelbrot(frc));
	else if (frc->fractol == 2)
		return (frc_bship(frc));
	else
		return (frc_tricorn(frc));
}
