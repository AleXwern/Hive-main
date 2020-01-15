/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:41:36 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/15 16:36:18 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		frc_mandelbrot(t_fractol *frc)
{
	int			iter;
	t_complex	z;

	z = set_complex(frc->c.re, frc->c.im);
	iter = 0;
	while (iter < frc->iter && (z.re * z.re) + (z.im * z.im) <= 4)
	{
		z = set_complex(z.re * z.re, z.im * z.im);
		z = set_complex(z.re - z.im + frc->c.re, 2.0 * z.re * z.im + frc->c.im);
		iter++;
	}
	return (iter);
}

int		frc_julia(t_fractol *frc)
{
	int			iter;
	t_complex	z;

	z = set_complex(frc->jul.re, frc->jul.im);
	iter = 0;
	while (iter < frc->iter && (z.re * z.re) + (z.im * z.im) <= 4)
	{
		z = set_complex(z.re * z.re, z.im * z.im);
		z = set_complex(z.re - z.im + frc->jul.re, 2.0 * z.re * z.im + frc->jul.im);
		iter++;
	}
	return (iter);
}

int		define_set(t_fractol *frc)
{
	if (frc->fractol == 1)
		return (frc_julia(frc));
	else
		return (frc_mandelbrot(frc));
}