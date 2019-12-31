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

void	heightgetter(t_fdf *fdf, int fd, char *av)
{
	char	*dummy;
	int		boolean;

	boolean = 0;
	while (get_next_line(fd, &dummy) == 1)
	{
		if (dummy[0] == 'z' && boolean == 0 && ft_strstr(av, ".xemo") != 0)
		{
			fdf->height = fdf->mallocht;
			boolean = 1;
		}
		else
			fdf->mallocht++;
		free(dummy);
	}
	if (fdf->height == 0)
		fdf->height = fdf->mallocht;
}

void	free_memory(char **arr)
{
	int y;

	y = 0;
	while (arr[y])
		y++;
	while (y >= 0)
		ft_strdel(&arr[y--]);
	free(arr);
	arr = NULL;
}

void	error_out(char *msg, t_fdf *fdf)
{
	ft_putendl(msg);
	if (!ft_strcmp(msg, F_ERROR) || !ft_strcmp(msg, USAGE) ||
			!ft_strcmp(msg, MEM_ERROR))
		exit(0);
	if (fdf->matrix)
		free(fdf->matrix);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
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
		heightgetter(fdf, fd, av[ac - 1]);
		close(fd);
		fdf_main(fdf, fd, av[ac - 1]);
	}
	ft_putendl(OOPS);
	return (0);
}
