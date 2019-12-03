/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:00:31 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/11/26 18:31:40 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*set_offset(int *offset, int x, int y, int *i)
{
	*i += 1;
	offset[0] = offset[2] - y;
	offset[1] = offset[3] - x;
	return (offset);
}

void	print_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_tetri	*blist;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	if (check_if_valid_file(fd, 0, 0, line) != 0)
	{
		ft_putendl("error");
		return (-1);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	comp_blocks(&blist, fd, 0, 'A');
	place_blocks(blist);
	return (0);
}
