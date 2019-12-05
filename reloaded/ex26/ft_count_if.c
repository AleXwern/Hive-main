/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:56:13 by anystrom          #+#    #+#             */
/*   Updated: 2019/10/18 11:12:15 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int		i;
	int		one;

	i = 0;
	one = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			one++;
		i++;
	}
	return (one);
}