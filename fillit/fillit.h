/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:29:45 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/11/26 18:29:13 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_tetri
{
	char			**block;
	int				x;
	int				y;
	char			alpha;
	struct s_tetri	*next;
}					t_tetri;

int					block_check(char **map, t_tetri *blist);
int					check_fit(char **map, t_tetri *blist, int x, int y);
int					check_if_valid_file(const int fd, int
							count, int index, char *line);
int					comp_blocks(t_tetri **blist, int fd, int i, char a);
int					count_tetri(t_tetri *blocks);
int					place_blocks(t_tetri *blocks);
int					*relative_offset(t_tetri *blist, int y, int x, int *i);
int					*set_offset(int *offset, int x, int y, int *i);
int					smallest_square(int i);

char				**allocate_map(int length);

void				reset_ints(int *coll, int *count, int *index);
void				free_list(t_tetri **tetri);
void				free_memory(char **arr);
void				print_map(char **map);

#endif
