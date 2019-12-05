/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:27:02 by anystrom          #+#    #+#             */
/*   Updated: 2019/10/16 15:42:53 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		rsize;
	int		*array;
	int		i;

	rsize = max - min;
	i = 0;
	if (rsize < 1)
		return (NULL);
	array = malloc(sizeof(int) * (rsize));
	while (min < max)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}
