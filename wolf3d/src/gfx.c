/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:41:51 by anystrom          #+#    #+#             */
/*   Updated: 2020/04/04 13:44:03 by AleXwern         ###   ########.fr       */
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
	gfx.wid = x;
	gfx.hgt = y;
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
	wolf->gfx[2] = gfx_get(wolf, ft_strjoin(bpath, "/wall.xpm"), 128, 128);
	wolf->gfx[3] = gfx_get(wolf, ft_strjoin(bpath, "/stairu.xpm"), 128, 128);
	wolf->gfx[4] = gfx_get(wolf, ft_strjoin(bpath, "/staird.xpm"), 128, 128);
	wolf->gfx[5] = gfx_get(wolf, ft_strjoin(bpath, "/door.xpm"), 128, 128);
	wolf->gfx[6] = gfx_get(wolf, ft_strjoin(bpath, "/warp.xpm"), 128, 128);
	wolf->gfx[7] = gfx_get(wolf, ft_strjoin("gfx/hud/", "notifup.xpm"), 441, 57);
	wolf->gfx[8] = gfx_get(wolf, ft_strjoin("gfx/hud/", "notifdown.xpm"), 441, 57);
	wolf->gfx[9] = gfx_get(wolf, ft_strjoin(bpath, "/battlebg.xpm"), WINX, WINY);
	wolf->gfx[10] = gfx_get(wolf, ft_strjoin("gfx/foe/", "foe3.xpm"), 188, 132);
	wolf->gfx[11] = gfx_get(wolf, ft_strjoin("gfx/hud/", "btlmenu.xpm"), 221, 312);
	wolf->gfx[12] = gfx_get(wolf, ft_strjoin("gfx/hud/", "btlsel.xpm"), 221, 312);
	free(bpath);
	ft_putendl("GFX compiled");
}
