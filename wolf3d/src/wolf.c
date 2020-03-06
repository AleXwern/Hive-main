/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:01:06 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/06 14:35:44 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	error_out(char *msg, t_wolf *wolf)
{
	ft_putendl(msg);
	if (wolf->winb == 1)
		mlx_destroy_window(wolf->mlx, wolf->win);
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
	mlx_hook(wolf->win, 2, 0, key_press, wolf);
	mlx_hook(wolf->win, 3, 0, key_release, wolf);
	mlx_hook(wolf->win, 17, 0, x_press, wolf);
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
	if (ac != 3)
		error_out(USAGE, wolf);
	wolf->tile = ft_atoi(av[1]);
	if (wolf->tile < 1 || wolf->tile > 6)
		error_out(USAGE, wolf);
	if (!(wolf->mlx = mlx_init()))
		error_out(MLX_ERROR, wolf);
	if (!(wolf->win = mlx_new_window(wolf->mlx, WINX, WINY, "Wolf3D")))
		error_out(WIN_ERROR, wolf);
	wolf->winb = 1;
	while (wolf->flr < 5)
		comp_map(wolf, av[2]);
	comp_gfx(wolf);
	setup(wolf);
	return (0);
}