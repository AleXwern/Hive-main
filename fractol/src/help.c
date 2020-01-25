/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:33:27 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/24 14:27:27 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Builds the needed string+number string that will be shown.
** NUM is freed here, DUMMY is freed on stats.
*/

char		*create_stats(int num, char *str)
{
	char	*strnum;
	char	*dummy;

	strnum = ft_itoa(num);
	dummy = ft_strjoin(str, strnum);
	free(strnum);
	return (dummy);
}

/*
** DUMMY is a dummy string that temprarily stores created strings
** that need to be shown on screen.
** Author hasn't done ft_printf so we'll go trough a bit more
** convoluted process.
*/

static void	stats(int x, int y, t_fractol *frc)
{
	char	*dummy;

	mlx_string_put(frc->mlx, frc->win, x, y, DATA, "DATA");
	dummy = create_stats(frc->iter, "Iterations: ");
	mlx_string_put(frc->mlx, frc->win, x, y + 20, DATA, dummy);
	free(dummy);
	dummy = create_stats(frc->threads, "Threads: ");
	mlx_string_put(frc->mlx, frc->win, x, y + 40, DATA, dummy);
	free(dummy);
	if (frc->fractol == 1)
	{
		if (frc->fixjulia)
			mlx_string_put(frc->mlx, frc->win, x, y + 60, DATA, DATA_O);
		else
			mlx_string_put(frc->mlx, frc->win, x, y + 60, DATA, DATA_F);
	}
}

/*
** Writes a quick reference of keys to upleft corner.
** Position is based on window size but text size cannot be changed
** which may cause severe clipping on smaller windows.
*/

void		help_window(t_fractol *frc)
{
	int		x;
	int		y;

	x = WINX / 25;
	y = WINY / 25;
	if (frc->ishelp)
	{
		mlx_string_put(frc->mlx, frc->win, x, y, HL, HLP);
		mlx_string_put(frc->mlx, frc->win, x, y + 20, HL, HLP_A);
		mlx_string_put(frc->mlx, frc->win, x, y + 40, HL, HLP_B);
		mlx_string_put(frc->mlx, frc->win, x, y + 60, HL, HLP_C);
		mlx_string_put(frc->mlx, frc->win, x, y + 80, HL, HLP_D);
		mlx_string_put(frc->mlx, frc->win, x, y + 100, HL, HLP_E);
		mlx_string_put(frc->mlx, frc->win, x, y + 120, HL, HLP_F);
		mlx_string_put(frc->mlx, frc->win, x, y + 140, HL, HLP_G);
		mlx_string_put(frc->mlx, frc->win, x, y + 160, HL, HLP_H);
		mlx_string_put(frc->mlx, frc->win, x, y + 180, HL, HLP_I);
		mlx_string_put(frc->mlx, frc->win, x, y + 200, HL, HLP_J);
		stats(x, y + 220, frc);
	}
}
