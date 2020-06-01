/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:01:06 by anystrom          #+#    #+#             */
/*   Updated: 2020/06/01 15:47:46 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

#include <stdio.h>

void	wolf_default(t_wolf *wlf)
{
	wlf->flr = 0;
	wlf->posx = 2.5;
	wlf->posy = 2.5;
	wlf->dirx = 1.0;
	wlf->diry = 0.0;
	wlf->planex = 0.0;
	wlf->planey = 0.66;
	wlf->rotsp = 0.05;
	wlf->movsp = 0.06;
	wlf->fcomb = 0;
	wlf->rng = 0.0;
	wlf->texbool = 1;
	wlf->sbox = WINX / 2;
	wlf->mxflr--;
	wlf->cur = 0;
	wlf->sel = -1;
	wlf->cycle = &render;
	ft_putendl("Defaults set");
	printf("Checking spawn with %d %d %d\n", 0, (int)wlf->posy, (int)wlf->posx);
	if (wlf->map[0][(int)wlf->posy][(int)wlf->posx] != 1)
	{
		ft_putnbr(wlf->map[0][(int)wlf->posy][(int)wlf->posx]);
		error_out(SPW_ERROR, wlf);
	}
	ft_putendl("Spawn fine.");
	pthread_create(&wlf->entity, NULL, (void *(*)(void *))testfunc,
				(void*)wlf);
	ft_putendl("Defaults set");
}

void	error_out(char *msg, t_wolf *wolf)
{
	ft_putendl(msg);
	wolf->fcomb = 1;
	if (wolf->winb == 1)
		mlx_destroy_window(wolf->mlx, wolf->win);
	//pthread_join(wolf->entity, NULL);
	//system("leaks wolf3d");
	exit(0);
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

void	setup(t_wolf *wolf)
{
	wolf_default(wolf);
	mlx_hook(wolf->win, 2, 0, key_hold, wolf);
	mlx_hook(wolf->win, 3, 0, key_release, wolf);
	mlx_hook(wolf->win, 17, 0, x_press, wolf);
	mlx_loop_hook(wolf->mlx, move, wolf);
	printf("Hello\n");
	wolf->cycle(wolf);
	mlx_loop(wolf->mlx);
}

int		main(int ac, char **av)
{
	t_wolf	*wolf;

	if (!(wolf = (t_wolf*)malloc(sizeof(t_wolf))))
	{
		ft_putendl(MEM_ERROR);
		exit (0);
	}
	wolf->winb = 0;
	wolf->flr = 0;
	if (ac != 4)
		error_out(USAGE, wolf);
	wolf->tile = ft_atoi(av[1]);
	if (wolf->tile < 1 || wolf->tile > 6)
		error_out(USAGE, wolf);
	wolf->mxflr = ft_atoi(av[2]);
	if (wolf->mxflr < 1 || wolf->mxflr > 9)
		error_out(USAGE, wolf);
	if (!(wolf->mlx = mlx_init()))
		error_out(MLX_ERROR, wolf);
	if (!(wolf->win = mlx_new_window(wolf->mlx, WINX, WINY, "Wolf3D")))
		error_out(WIN_ERROR, wolf);
	wolf->winb = 1;
	printf("Floors: %d Palette: %d CurFloor: %d\n", wolf->mxflr, wolf->tile, wolf->flr);
	comp_map(wolf, av[3]);
	comp_gfx(wolf);
	printf("Floors: %d Palette: %d CurFloor: %d\n", wolf->mxflr, wolf->tile, wolf->flr);
	setup(wolf);
	return (0);
}