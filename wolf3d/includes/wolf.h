/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:31:21 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/04 13:53:16 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_chara
{
	char		*name;
	int			hp;
	int			defend;
	int			row;
}				t_chara;

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
	int			winb;
	int			rng;
	int			aggro;
	int			iscombat;
	int			ismenu;
}				t_wolf;

#endif