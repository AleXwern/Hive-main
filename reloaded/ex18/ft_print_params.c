/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:13:55 by anystrom          #+#    #+#             */
/*   Updated: 2019/10/16 11:11:13 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_printout(int argc, char **argv, int a, int c)
{
	while (a < argc)
	{
		while (argv[a][c] != '\0')
		{
			ft_putchar(argv[a][c]);
			c++;
		}
		ft_putchar('\n');
		c = 0;
		a++;
	}
}

int		main(int argc, char **argv)
{
	ft_printout(argc, argv, 1, 0);
	return (0);
}
