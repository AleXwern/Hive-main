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

int		centerid(t_fdf *fdf, int x, int y)
{
	int		id;

	id = 0;
	while (id < fdf->height * fdf->width)
	{
		if (fdf->matrix[id].x == x && fdf->matrix[id].y == y)
			return (id);
		id++;
	}
	return (-1);
}

void	fdf_init(t_fdf *fdf, char **av)
{
	char	*title;

	title = ft_strjoin(av[1], " - FDF render");
	fdf->top = 0;
	fdf->rlsin = 0;
	fdf->rlflt = 0;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WINX, WINY, title);
	free(title);
	fdf->posx = WINX / 2;
	fdf->posy = WINY / 2;
}

void	fdf_main(t_fdf *fdf, int fd, char **av)
{
	fd = open(av[1], O_RDONLY);
	fdf_init(fdf, av);
	fileformat(fd, fdf);
	close(fd);
	fdf->pad = (int)floor((WINX / 3) / fdf->width);
	if ((fdf->center = centerid(fdf, floor(fdf->width / 2),
			floor(fdf->height / 2))) == -1)
		error_out(OOPS, fdf);
	draw_image(fdf, 0);
	mlx_key_hook(fdf->win, key_main, fdf);
	mlx_loop(fdf->mlx);
}
