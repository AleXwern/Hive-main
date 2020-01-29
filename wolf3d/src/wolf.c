/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:01:06 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/24 16:07:41 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	error_out(char *msg, t_wolf *wolf)
{
	if (wolf->winb == 1)
		mlx_destroy_window(wolf->mlx, wolf->win);
	exit(0);
}

int		main(int ac, char **av)
{
	t_wolf	*wolf;

	if (!(wolf = (t_wolf*)malloc(sizeof(t_wolf))))
		error_out(MEM_ERROR, wolf);
	if (ac != 2)
		error_out(USAGE, wolf);
	if (!(wolf->mlx = mlx_init()))
		error_out(MLX_ERROR, wolf);
	if (!(wolf->win = mlx_new_window(wolf->mlx, WINX, WINY, "Wolf3D")))
		error_out(WIN_ERROR, wolf);
	wolf->winb = 1;
	
	return (0);
}