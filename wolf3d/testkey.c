/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testkey.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 12:32:43 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/13 12:37:07 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../libft/libft.h"

int		putmem(int key, void *vid)
{
	ft_putnbr(key);
	ft_putendl("");
	return (0);
}

int		main(void)
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 200, 200 ,"juu");
	void	*vid;
	mlx_key_hook(win, putmem, vid);
	mlx_loop(mlx);
}