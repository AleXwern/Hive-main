/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:01:58 by exam              #+#    #+#             */
/*   Updated: 2020/01/21 14:59:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		checkketeer(char br, char str)
{
	if (br == '(' && str == ')')
		return (1);
	else if (br == '[' && str == ']')
		return (1);
	else if (br == '{' && str == '}')
		return (1);
	else
		return (0);
}

int		bracceteer(int i, char br, char *str)
{
	while (str[i] != '\0')
	{
		if ((str[i] == ']' || str[i] == ')' || str[i] == '}')
				&& !checkketeer(br, str[i]))
			return (-1);
		if (checkketeer(br, str[i]))
			return (i);
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			i = bracceteer(i + 1, str[i], str);
		if (i == -1)
			return (-1);
		i++;
	}
	if (str[i] == '\0' && br == '\0')
		return (1);
	else
		return (-1);
}

int		main(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (bracceteer(0, '\0', av[i]) != -1)
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		i++;
	}
	if (ac == 1)
		write(1, "\n", 1);
	return (0);
}
