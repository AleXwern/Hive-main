/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:13:55 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/01 15:20:10 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	heightgetter(t_fdf *fdf, int fd)
{
	char	*dummy;

	dummy = ft_strnew(1);
	while (get_next_line(fd, &dummy) == 1)
	{
		fdf->height++;
	}
	if (dummy)
		ft_strdel(&dummy);
}

void	error_out(char *msg, t_fdf *fdf)
{
	ft_putendl(msg);
	if (fdf)
	{
		if (fdf->matrix != NULL)
			ft_memdel((void**)fdf->matrix);
		if (fdf->mlx)
			ft_memdel((void**)fdf->mlx);
		if (fdf->win)
			ft_memdel((void**)fdf->win);
		ft_memdel((void**)fdf);
	}
	exit(0);
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;
	int		fd;

	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		error_out(MEM_ERROR, fdf);
	if (ac != 2)
		error_out(USAGE, fdf);
	else
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			error_out(F_ERROR, fdf);
		heightgetter(fdf, fd);
		close(fd);
		open(av[1], O_RDONLY);
		fdf_main(fdf, fd, av[1]);
	}
	return(0);
}