/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:31:21 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/11 14:19:56 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

/*
** Party member info
** name		= party member name
** maxhp	= max HP
** hp		= current hp
** defend	= 1 if defend option was chosen
** row		= front or back row
** DEFEND and BACK ROW reduce damage by half (stackable)
** BACK ROW reduce damage dealt
*/

typedef struct	s_chara
{
	char		*name;
	int			maxhp;
	int			hp;
	int			defend;
	int			row;
}				t_chara;

/*
** GFX library
** 0 = Skybox
** 1 = Floor
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

/*
** mlx	= MLX pointer
** win	= WIN pointer
** pc	= player info
** tile	= graphic set
** gfx	= library of graphics
** menucur	= COMBAT: cursor position
** menugfx	= COMBAT: menu gfx
** img	= current scene render
** chara	= list of party members
** x	= screen X pos
** y	= screen Y pos
** spawn	= spawn XY pos
** hold
** flr
** mapset
** map
** winb
** rng
** fcomb
** aggro
** iscombat
** ismenu
*/

typedef struct	s_wolf
{
	void		*mlx;
	void		*win;
	t_player	pc;
	int			tile;
	t_gfx		gfx[256];
	int			menucur;
	t_gfx		menugfx[5];
	t_gfx		img;
	t_chara		chara[5];
	int			x;
	int			y;
	int			spawn[2];
	int			hold;
	int			flr;
	int			mapset;
	int			map[5][25][25];
	int			winb;
	double		rng;
	int			fcomb;
	int			aggro;
	int			iscombat;
	int			ismenu;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineh;
	int			start;
	int			end;
	int			texnum;
	int			texx;
	int			texy;
	int			testcolor;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camx;
	double		raydx;
	double		raydy;
	double		sidedx;
	double		sidedy;
	double		deltadx;
	double		deltady;
	double		walldist;
	double		movsp;
	double		rotsp;
	double		step;
	double		wallx;
	double		texpos;
}				t_wolf;

t_gfx			init_image(t_wolf *wolf, int x, int y);

int				key_press(int key, t_wolf *wolf);
int				key_release(int key, t_wolf *wolf);			
int				move_fb(int key, t_wolf *wlf);
int				move_lr(int key, t_wolf *wlf);
int				x_press(t_wolf *wolf);

void			comp_gfx(t_wolf *wolf);
void			comp_map(t_wolf *wolf, char *av);
void			error_out(char *msg, t_wolf *wolf);
void			free_memory(char **arr);
void			render(t_wolf *wlf);
void			wall_stripe(t_wolf *wlf);

#endif
