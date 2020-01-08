/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:52:04 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/08 15:58:18 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_main(int key, t_fractol *frc)
{
	ft_putnbr(key);
	ft_putendl("");
	if (key == ESC)
		error_out(FINE, frc);
	return (0);
}