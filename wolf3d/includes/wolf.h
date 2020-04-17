/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:31:21 by anystrom          #+#    #+#             */
/*   Updated: 2020/04/15 12:03:43 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "/usr/X11/include/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <pthread.h>

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
	int			row;
	int			action;
}				t_chara;

/*
** GFX library
** 0 = Skybox
** 1 = Floor
** 2 = Wall
** 3 = Stairs up
** 4 = Stairs down
** 5 = Door
** 6 = Secret warp
*/

typedef struct	s_gfx
{
	void		*img;
	int			*data;
	int			sizel;
	int			bpp;
	int			endn;
	int			wid;
	int			hgt;
}				t_gfx;

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
	int			tile;
	t_gfx		gfx[256];
	t_gfx		img;
	t_chara		chara[5];
	pthread_t	entity;
	void		(*cycle)(struct s_wolf*);
	int			cur;
	int			sel;
	int			plr;
	int			x;
	int			y;
	int			pos;
	int			spawn[2];
	int			hold;
	int			flr;
	int			mxflr;
	int			mapset;
	int			map[9][25][25];
	int			winb;
	int			texbool;
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
	int			sbox;
	int			cellx;
	int			celly;
	int			tx;
	int			ty;
	double		posx;
	double		posy;
	double		posz;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camx;
	double		raydx;
	double		raydy;
	double		raydx0;
	double		raydy0;
	double		raydx1;
	double		raydy1;
	double		sidedx;
	double		sidedy;
	double		deltadx;
	double		deltady;
	double		walldist;
	double		wdarr[1080];
	double		rowdist;
	double		flstepx;
	double		flstepy;
	double		floorx;
	double		floory;
	double		movsp;
	double		rotsp;
	double		step;
	double		wallx;
	double		texpos;
}				t_wolf;

t_gfx			init_image(t_wolf *wolf, int x, int y);

int				interact(t_wolf *wlf);
int				key_press(int key, t_wolf *wolf);
int				key_release(int key, t_wolf *wolf);			
int				move_fb(int key, t_wolf *wlf);
int				move_lr(int key, t_wolf *wlf);
int				x_press(t_wolf *wolf);

void			comp_gfx(t_wolf *wolf);
void			comp_map(t_wolf *wolf, char *av);
void			draw_gfx(t_wolf *wlf, t_gfx gfx, int x, int y);
void			encounter(t_wolf *wlf);
void			error_out(char *msg, t_wolf *wolf);
void			free_memory(char **arr);
void			lab_move(t_wolf *wlf, int obj);
void			render(t_wolf *wlf);
void			render_floor(t_wolf *wlf, int y);
void			wall_stripe(t_wolf *wlf);

void	testfunc(t_wolf *wlf);

#endif
