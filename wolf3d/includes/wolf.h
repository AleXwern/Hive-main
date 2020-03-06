/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:31:21 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/06 14:35:00 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct	s_chara
{
	char		*name;
	int			hp;
	int			defend;
	int			row;
}				t_chara;

/*
** GFX library
** 0 = Skybox
*/

typedef struct	s_gfx
{
	void		*img;
	char		*data;
	int			sizel;
	int			bpp;
	int			endn;
}				t_gfx;

typedef struct	s_player
{
	double		posx;
	double		posy;
}				t_player;

typedef struct	s_wolf
{
	void		*mlx;
	void		*win;
	t_player	pc;
	int			tile;
	t_gfx		gfx[256];
	int			menucur;
	t_gfx		menugfx[5];
	t_chara		chara[5];
	int			spawn[2];
	int			hold;
	int			flr;
	int			mapset;
	int			map[5][25][25];
	int			winb;
	int			rng;
	int			aggro;
	int			iscombat;
	int			ismenu;
}				t_wolf;

int				key_press(int key, t_wolf *wolf);
int				key_release(int key, t_wolf *wolf);
int				x_press(t_wolf *wolf);


void			comp_gfx(t_wolf *wolf);
void			comp_map(t_wolf *wolf, char *av);
void			error_out(char *msg, t_wolf *wolf);
void			free_memory(char **arr);

#endif
