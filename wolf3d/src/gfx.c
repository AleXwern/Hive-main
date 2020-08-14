/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:41:51 by anystrom          #+#    #+#             */
/*   Updated: 2020/08/12 11:32:34 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/value.h"

void	destroy_gfx(t_wolf *wlf, int i)
{
	while (++i < wlf->gfxcount)
	{
		mlx_destroy_image(wlf->mlx, wlf->gfx[i].img);
	}
	free(wlf->gfx);
}

t_gfx	init_image(t_wolf *wlf, int x, int y)
{
	t_gfx		img;

	img.img = mlx_new_image(wlf->mlx, WINX, WINY);
	img.data = (int*)mlx_get_data_addr(img.img, &(img.bpp), &(img.sizel),
			&(img.endn));
	return (img);
}

t_gfx	gfx_get(t_wolf *wlf, char *file, int x, int y)
{
	t_gfx	gfx;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_out(GFX_ERROR, wlf, 0);
	gfx.img = mlx_xpm_file_to_image(wlf->mlx, file, &x, &y);
	gfx.data = (int*)mlx_get_data_addr(gfx.img, &gfx.bpp,
			&gfx.sizel, &gfx.endn);
	gfx.wid = x;
	gfx.hgt = y;
	free(file);
	close(fd);
	return (gfx);
}

void	comp_hud_gfx(t_wolf *wlf, char *bpath, int i)
{
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin("gfx/hud/", "notifup.xpm"),
			41, 57);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin("gfx/hud/", "notifdown.xpm"),
			441, 57);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin(bpath, "/battlebg.xpm"),
			WINX, WINY);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin("gfx/foe/", "foe3.xpm"),
			564, 396);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin("gfx/hud/", "btlmenu.xpm"),
			221, 312);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin("gfx/hud/", "btlsel.xpm"),
			221, 312);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin("gfx/hud/", "pcturn.xpm"),
			354, 95);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin("gfx/hud/", "pcsel.xpm"),
			354, 95);
	comp_foe(wlf, bpath, i);
}

void	comp_gfx(t_wolf *wlf, int i)
{
	char	*bpath;

	wlf->tile += 48;
	bpath = ft_strjoin("gfx/", (char*)&(wlf->tile));
	if (!(wlf->gfx = (t_gfx*)malloc(sizeof(t_gfx) * GFXCOUNT)))
		error_out(MEM_ERROR, wlf, 0);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin(bpath, "/sky.xpm"), 1080, 360);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin(bpath, "/floor.xpm"), 128, 128);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin(bpath, "/wall.xpm"), 128, 128);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin(bpath, "/stairu.xpm"), 128, 128);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin(bpath, "/staird.xpm"), 128, 128);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin(bpath, "/door.xpm"), 128, 128);
	wlf->gfx[i++] = gfx_get(wlf, ft_strjoin(bpath, "/warp.xpm"), 128, 128);
	comp_hud_gfx(wlf, bpath, i);
}
