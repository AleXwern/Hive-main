/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chess.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:08:25 by exam              #+#    #+#             */
/*   Updated: 2020/01/28 15:11:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHESS_H
# define CHESS_H

# include <stdlib.h>
# include <unistd.h>

int		pawn_move(int wid, char **brd, int x, int y);
int		bishop_move(int wid, char **brd, int x, int y);
int		rook_move(int wid, char **brd, int x, int y);
int		queen_move(int wid, char **brd, int x, int y);

#endif
