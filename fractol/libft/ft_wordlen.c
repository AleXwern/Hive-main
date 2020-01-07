/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:29:16 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/02 15:29:17 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordlen(char const *str, char del)
{
	int		len;

	len = 0;
	while (str[len] != '\0' && str[len] != del)
		len++;
	return (len--);
}
