/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:11:48 by anystrom          #+#    #+#             */
/*   Updated: 2019/10/16 14:25:25 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_printout(int n, char *argv)
{
	while (argv[n] != '\0')
	{
		ft_putchar(argv[n]);
		n++;
	}
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	while ((i + 1) < argc)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			argv[argc + 1] = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = argv[argc + 1];
			i = 0;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_printout(0, argv[i]);
		ft_putchar('\n');
		i++;
	}
}
