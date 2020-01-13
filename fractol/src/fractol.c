/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:52:31 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/13 17:12:06 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	testdraw(t_fractol *frc)
{

}

t_image	*init_image(t_fractol *frc)
{
	t_image		*img;

	if (!(img = (t_image*)malloc(sizeof(t_image))))
		error_out(MEM_ERROR, frc);
	if (!(img->img = mlx_new_image(frc->mlx, WINX, WINY)))
		error_out(IMG_ERROR, frc);
	img->data = mlx_get_data_addr(img->img, &(img->bpp), &(img->sizel),
			&(img->endn));
	return (img);
}

void	fractol_main(t_fractol *frc)
{
	frc->img = init_image(frc);
	testdraw(frc);
	mlx_put_image_to_window(frc->mlx, frc->win, frc->img, 0, 0);
	mlx_key_hook(frc->win, key_main, frc);
	if (!frc->fixjulia)
		mlx_hook(frc->win, 6, 0, julia_move, frc);
	mlx_mouse_hook(frc->win, mouse_main, frc);
	if (frc->ishelp)
		help_window(frc);
	mlx_loop(frc->mlx);
}