/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arggetter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:13:55 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/01 15:20:10 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		basecheck(char str, char *basel, char *baseu)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (str == basel[i] || str == baseu[i])
			return (i);
		i++;
	}
	return (0);
}

int		av_atoi_base(char *str, char *basel, char *baseu)
{
	int		num;
	int		neg;

	num = 0;
	neg = 1;
	if (str == NULL)
		return (0);
	while (ft_isblank(*str))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (basecheck(*str, basel, baseu) && *str != '\0')
	{
		num = num * 16;
		num += basecheck(*str, basel, baseu);
		str++;
	}
	if (num > 0xffffff)
		num = 0xffffff;
	return (num * neg);
}

int		colouratoi(char *av)
{
	if (av[0] == '\0')
		return (0);
	if (av[0] != '0' || av[1] != 'x')
		return (0);
	return (av_atoi_base(av + 2, "0123456789abcdef", "0123456789ABCDEF"));
}

void	arggetter(t_fdf *fdf, char **av, int ac)
{
	int		i;

	i = 1;
	ft_putendl("Hello");
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-color") && i != ac - 1)
			fdf->iscolour = colouratoi(av[i + 1]);
		else if (!ft_strcmp(av[i], "-nolink"))
			fdf->islink = 0;
		i++;
	}
	ft_putendl("Hello");
}