/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:41:51 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/09 14:44:41 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

t_gfx	init_image(t_wolf *wolf, int x, int y)
{
	t_gfx		img;

	img.img = mlx_xpm_file_to_image(wolf->mlx, "gfx/img.xpm", &x, &y);
	img.data = mlx_get_data_addr(img.img, &(img.bpp), &(img.sizel),
			&(img.endn));
	return (img);
}

t_gfx	gfx_get(t_wolf *wolf, char *file, int x, int y)
{
	t_gfx	gfx;
	int		fd;

	fd = open(file, O_RDONLY);
	ft_putendl(file);
	if (fd == -1)
		error_out(GFX_ERROR, wolf);
	gfx.img = mlx_xpm_file_to_image(wolf->mlx, file, &x, &y);
	gfx.data = mlx_get_data_addr(gfx.img, &gfx.bpp, &gfx.sizel, &gfx.endn);
	free(file);
	close(fd);
	return (gfx);
}

void	comp_gfx(t_wolf *wolf)
{
	char	*bpath;

	wolf->tile += 48;
	bpath = ft_strjoin("gfx/", (char*)&(wolf->tile));
	wolf->img = init_image(wolf, WINX, WINY);
	wolf->gfx[0] = gfx_get(wolf, ft_strjoin(bpath, "/sky.xpm"), 1080, 360);
	wolf->gfx[1] = gfx_get(wolf, ft_strjoin(bpath, "/floor.xpm"), 1080, 360);
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->gfx[0].img, 0, 0);
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->gfx[1].img, 0, 360);
	ft_putendl("GFX compiled");
}
