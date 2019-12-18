/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:13:55 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/01 15:20:10 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_init(t_fdf *fdf, char *av)
{
	av = ft_strjoin(av, " - FDF render");
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WINX, WINY, av);
	fdf->pad = (int)floor((WINX / 3) / fdf->width);
	fdf->posx = (int)floor((WINX / 2) - (fdf->pad * fdf->width / 2));
	fdf->posy = (int)floor((WINY / 2) - (fdf->pad * fdf->height / 2));
}

void	fdf_main(t_fdf *fdf, int fd, char *av)
{
	int		i;

	i = 0;
	fileformat(fd, fdf);
	fdf_init(fdf, av);
	while (i < fdf->height * fdf->width)
	{
		printf("ID:%d X:%d Y:%d Z:%d Left:%d Up:%d\n", i, fdf->matrix[i].x, fdf->matrix[i].y, fdf->matrix[i].z, fdf->matrix[i].left, fdf->matrix[i].up);
		i++;
	}
	draw_image(fdf, 0);
	mlx_key_hook(fdf->win, key_main, fdf);
	mlx_mouse_hook(fdf->win, mouse_main, fdf);
	mlx_loop(fdf->mlx);
}