/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:33:27 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/13 15:50:52 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	help_window(t_fractol *frc)
{
	int		x;
	int		y;

	x = WINX / 25;
	y = WINY / 25;
	mlx_string_put(frc->mlx, frc->win, x, y, HL, "HELP");
	mlx_string_put(frc->mlx, frc->win, x, y + 20, HL, "ESC to exit");
	mlx_string_put(frc->mlx, frc->win, x, y + 40, HL, "R to reset");
	mlx_string_put(frc->mlx, frc->win, x, y + 60, HL, "SPACE to stop julia");
	mlx_string_put(frc->mlx, frc->win, x, y + 80, HL, "ARROW to move");
	mlx_string_put(frc->mlx, frc->win, x, y + 100, HL, "H to open help");
	mlx_string_put(frc->mlx, frc->win, x, y + 120, HL, "R to reset");
	mlx_string_put(frc->mlx, frc->win, x, y + 140, HL, "123 to change factal");
	mlx_string_put(frc->mlx, frc->win, x, y + 160, HL, "C to change color");
	mlx_string_put(frc->mlx, frc->win, x, y + 180, HL, "SCROLL to zoom");
}