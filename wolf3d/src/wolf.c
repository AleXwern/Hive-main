/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:01:06 by anystrom          #+#    #+#             */
/*   Updated: 2020/05/24 23:54:59 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	wolf_default(t_wolf *wlf)
{
	wlf->flr = 0;
	wlf->posx = 3.5;
	wlf->posy = 3.5;
	wlf->dirx = 1.0;
	wlf->diry = 0.0;
	wlf->planex = 0.0;
	wlf->planey = 0.66;
	wlf->rotsp = 0.1;
	wlf->movsp = 0.1;
	wlf->fcomb = 0;
	wlf->rng = 0.0;
	wlf->texbool = 1;
	wlf->sbox = WINX / 2;
	wlf->mxflr--;
	wlf->cur = 0;
	wlf->sel = -1;
	wlf->cycle = &render;
	if (wlf->map[0][(int)wlf->posy][(int)wlf->posx] != 1)
		error_out(FIL_ERROR, wlf);
	pthread_create(&wlf->entity, NULL, (void *(*)(void *))testfunc,
				(void*)wlf);
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
	mlx_key_hook(wolf->win, key_press, wolf);
	//mlx_hook(wolf->win, 2, 0, key_press, wolf);
	//mlx_hook(wolf->win, 3, 0, key_release, wolf);
	mlx_hook(wolf->win, 17, 0, x_press, wolf);
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
	comp_map(wolf, av[3]);
	comp_gfx(wolf);
	setup(wolf);
	return (0);
}