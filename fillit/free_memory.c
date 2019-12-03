/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:53:11 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/11/20 13:18:28 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	free_list(t_tetri **tetri)
{
	t_tetri	*tmp;

	tmp = *tetri;
	while (*tetri)
	{
		tmp = *tetri;
		*tetri = (*tetri)->next;
		free_memory(tmp->block);
		free(tmp);
	}
	free(*tetri);
	*tetri = NULL;
}
