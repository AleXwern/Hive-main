/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:01:06 by anystrom          #+#    #+#             */
/*   Updated: 2020/06/15 14:26:29 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	key_defaults(t_wolf *wlf)
{
	wlf->keydown = 0;
	wlf->keyleft = 0;
	wlf->keyright = 0;
	wlf->keyup = 0;
}

void	wolf_default(t_wolf *wlf)
{
	wlf->flr = 0;
	wlf->posx = 2.5;
	wlf->posy = 2.5;
	wlf->dirx = 1.0;
	wlf->diry = 0.0;
	wlf->planex = 0.0;
	wlf->planey = 0.66;
	wlf->rotsp = 0.03;
	wlf->movsp = 0.04;
	wlf->rng = 0.0;
	wlf->texbool = 1;
	wlf->sbox = WINX / 2;
	wlf->mxflr--;
	wlf->cur = 0;
	wlf->sel = -1;
	wlf->plr = 0;
	wlf->plrck = 0;
	wlf->cycle = &render;
	wlf->chara = generate_party(wlf);
	wlf->syssmg[0] = ft_strdup("You encountered a strong beast!");
	wlf->syssmg[1] = ft_strdup("What will you do?");
	key_defaults(wlf);
}

void	error_out(char *msg, t_wolf *wlf, int y)
{
	ft_putendl(msg);
	if (!ft_strcmp(msg, WLF_ERROR))
		exit(0);
	if (!ft_strcmp(msg, FLR_ERROR))
		wlf->mxflr = wlf->flr - 49;
	if (wlf->syssmg[0])
	{
		free(wlf->syssmg[0]);
		free(wlf->syssmg[1]);
	}
	if (wlf->gfx)
		destroy_gfx(wlf, -1);
	if (y > 0)
		free_layer(wlf, wlf->flr, -1, y);
	if (wlf->map)
		free_map(wlf, -1, -1);
	if (wlf->winb == 1)
		mlx_destroy_window(wlf->mlx, wlf->win);
	exit(0);
}

void	setup(t_wolf *wlf)
{
	wolf_default(wlf);
	if (wlf->map[0][(int)wlf->posy][(int)wlf->posx] != 1)
		error_out(SPW_ERROR, wlf, 0);
	mlx_hook(wlf->win, 2, 0, key_hold, wlf);
	mlx_hook(wlf->win, 3, 0, key_release, wlf);
	mlx_hook(wlf->win, 17, 0, x_press, wlf);
	mlx_loop_hook(wlf->mlx, move, wlf);
	wlf->cycle(wlf);
	mlx_loop(wlf->mlx);
}

int		main(int ac, char **av)
{
	t_wolf	*wlf;

	if (!(wlf = (t_wolf*)malloc(sizeof(t_wolf))))
		error_out(WLF_ERROR, wlf, 0);
	ft_bzero(wlf, sizeof(t_wolf));
	if (ac != 4)
		error_out(USAGE, wlf, 0);
	wlf->tile = ft_atoi(av[1]);
	if (wlf->tile < 1 || wlf->tile > 6)
		error_out(USAGE, wlf, 0);
	wlf->mxflr = ft_atoi(av[2]);
	if (wlf->mxflr < 1 || wlf->mxflr > 9)
		error_out(USAGE, wlf, 0);
	if (!(wlf->mlx = mlx_init()))
		error_out(MLX_ERROR, wlf, 0);
	if (!(wlf->win = mlx_new_window(wlf->mlx, WINX, WINY, "Wolf3D")))
		error_out(WIN_ERROR, wlf, 0);
	wlf->winb = 1;
	comp_map(wlf, av[3]);
	comp_gfx(wlf, 0);
	setup(wlf);
	return (0);
}
