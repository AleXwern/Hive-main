/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:41:51 by anystrom          #+#    #+#             */
/*   Updated: 2020/03/25 00:53:22 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

t_gfx	init_image(t_wolf *wlf, int x, int y)
{
	t_gfx		img;

	//img.img = mlx_xpm_file_to_image(wlf->mlx, "gfx/img.xpm", &x, &y);
	img.img = mlx_new_image(wlf->mlx, WINX, WINY);
	img.data = (int*)mlx_get_data_addr(img.img, &(img.bpp), &(img.sizel),
			&(img.endn));
	//mlx_put_image_to_window(wlf->mlx, wlf->win, wlf->gfx[0].img, 0, 0);
	//mlx_put_image_to_window(wlf->mlx, wlf->win, wlf->gfx[1].img, 0, 360);
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
	gfx.data = (int*)mlx_get_data_addr(gfx.img, &gfx.bpp, &gfx.sizel, &gfx.endn);
	free(file);
	close(fd);
	return (gfx);
}

void	comp_gfx(t_wolf *wolf)
{
	char	*bpath;

	wolf->tile += 48;
	bpath = ft_strjoin("gfx/", (char*)&(wolf->tile));
	wolf->gfx[0] = gfx_get(wolf, ft_strjoin(bpath, "/sky.xpm"), 1080, 360);
	wolf->gfx[1] = gfx_get(wolf, ft_strjoin(bpath, "/floor.xpm"), 128, 128);
	wolf->gfx[2] = gfx_get(wolf, ft_strjoin(bpath, "/wall.xpm"), 64, 64);
	wolf->gfx[3] = gfx_get(wolf, ft_strjoin(bpath, "/stairu.xpm"), 64, 64);
	wolf->gfx[4] = gfx_get(wolf, ft_strjoin(bpath, "/staird.xpm"), 64, 64);
	wolf->gfx[5] = gfx_get(wolf, ft_strjoin(bpath, "/door.xpm"), 64, 64);
	wolf->gfx[6] = gfx_get(wolf, ft_strjoin(bpath, "/warp.xpm"), 64, 64);
	//mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->gfx[0].img, 0, 0);
	//mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->gfx[1].img, 0, 360);
	free(bpath);
	ft_putendl("GFX compiled");
}
