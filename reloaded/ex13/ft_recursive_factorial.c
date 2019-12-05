/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:40:05 by anystrom          #+#    #+#             */
/*   Updated: 2019/10/18 11:32:32 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_calculator(int nb, int mult)
{
	if (mult > 1)
		nb = ft_recursive_calculator(nb * mult, mult - 1);
	return (nb);
}

int		ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	return (ft_recursive_calculator(nb, nb - 1));
}
