/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:36:24 by vsanta            #+#    #+#             */
/*   Updated: 2019/05/14 21:18:54 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_puterror(char *str)
{
	ft_putendl(str);
	exit(1);
}

static int	img_init(t_cfg *cfg)
{
	if ((cfg->connect = mlx_init()) == NULL)
		return (0);
	if ((cfg->window = mlx_new_window(cfg->connect, WIN_W, WIN_H, WIN_TITLE))
	== NULL)
		return (0);
	if ((cfg->img_con = mlx_new_image(cfg->connect, WIN_W, WIN_H)) == NULL)
		return (0);
	cfg->img = (int*)mlx_get_data_addr(cfg->img_con,
			&cfg->bpp, &cfg->size_l, &cfg->endian);
	return (1);
}

static void	cam_init(t_cam *cam, t_map map)
{
	cam->scale = WIN_H / (map.h - 1) / 3;
	cam->s_x = (map.w - 1) * cam->scale / -2 + ((map.w - 1) / 2) * cam->scale;
	cam->s_y = (map.h - 1) * cam->scale / -2 + ((map.h - 1) / 2) * cam->scale;
	cam->x = 0;
	cam->y = 0;
	cam->z = 0;
	cam->view = 'i';
}

int			main(int ac, char **av)
{
	t_fdf	fdf;

	fdf.str = av[1];
	fdf.map.cords = NULL;
	if (ac == 1)
		ft_puterror("usage: ./fdf [filename]");
	if (img_init(&fdf.cfg) == 0)
		ft_puterror("error!");
	fdf.map.max_d = 0;
	fdf.map.min_d = 0;
	if (reader(av[1], &fdf.map) == 0)
	{
		ft_puterror("error!");
		return (cleaner(NULL, NULL, (void****)&fdf.map.cords));
	}
	cam_init(&fdf.cam, fdf.map);
	mlx_hook(fdf.cfg.window, 17, 0, &ft_close, &fdf);
	mlx_hook(fdf.cfg.window, 2, 0, &events_keyboard, &fdf);
	draw_map(fdf.map, fdf.cam, fdf.cfg);
	put_wdw(fdf.cfg.connect, fdf.cfg.window, fdf.cfg.img_con, fdf.cam.view);
	mlx_loop(fdf.cfg.connect);
	return (0);
}
