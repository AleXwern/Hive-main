/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JessicaNystrom <JessicaNystrom@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:00:58 by JessicaNyst       #+#    #+#             */
/*   Updated: 2020/02/05 14:34:46 by JessicaNyst      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../../vulkansdk/MoltenVK/include/vulkan/vulkan.h"

int		main(int ac, char **av)
{
	VkInstance				inst;
	VkResult				res;
	VkInstanceCreateInfo	info;

	res = vkCreateInstance(&info, NULL, &inst);
	ft_putendl((char*)res);
	vkDestroyInstance(inst, NULL);
	return (0);
}