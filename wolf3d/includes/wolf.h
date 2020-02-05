/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:31:21 by anystrom          #+#    #+#             */
/*   Updated: 2020/01/24 17:18:25 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_player
{
	double		posx;
	double		posy;
}				t_player;

typedef struct	s_wolf
{
	void		*mlx;
	void		*win;
	t_player	pc;
	int			winb;
}				t_wolf;

#endif