/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:55:31 by anystrom          #+#    #+#             */
/*   Updated: 2019/10/17 12:39:40 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		sqrt;

	sqrt = 1;
	if (nb <= 0)
	{
		return (0);
	}
	while ((sqrt * sqrt) <= nb)
	{
		if ((sqrt * sqrt) == nb)
		{
			return (sqrt);
		}
		else
		{
			sqrt++;
		}
	}
	return (0);
}
