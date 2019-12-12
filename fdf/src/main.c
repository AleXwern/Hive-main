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

void	error_out(char *msg)
{
	ft_putendl(msg);
	exit(0);
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;
	int		fd;

	if (!(fd = malloc(sizeof(t_fdf))))
		error_out(MEM_ERROR);
	if (ac != 2)
		error_out(A_ERROR);
	else
	{
		if ((fd = open(av[1])) == -1)
			error_out(F_ERROR);
		fdf_main(&fdf, fd);
	}
	return(0);
}