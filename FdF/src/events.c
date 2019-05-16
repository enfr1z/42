/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:30:13 by pdiedra           #+#    #+#             */
/*   Updated: 2019/05/14 21:08:44 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		view_move(int keycode, t_fdf *fdf)
{
	if (keycode == 0 || keycode == 123)
		fdf->cam.s_x -= 5;
	if (keycode == 2 || keycode == 124)
		fdf->cam.s_x += 5;
	if (keycode == 1 || keycode == 125)
		fdf->cam.s_y += 5;
	if (keycode == 13 || keycode == 126)
		fdf->cam.s_y -= 5;
}

static void		zoom(int keycode, t_fdf *fdf)
{
	if (keycode == 69 || keycode == 24)
		fdf->cam.scale += 2;
	if (keycode == 78 || keycode == 27)
		fdf->cam.scale -= 2;
}

static void		rotation(int keycode, t_fdf *fdf)
{
	if (keycode == 86 && fdf->cam.view == 'v')
		fdf->cam.y -= 0.3;
	if (keycode == 88 && fdf->cam.view == 'v')
		fdf->cam.y += 0.3;
	if (keycode == 91 && fdf->cam.view == 'v')
		fdf->cam.x -= 0.3;
	if (keycode == 84 && fdf->cam.view == 'v')
		fdf->cam.x += 0.3;
	if (keycode == 92 && fdf->cam.view == 'v')
		fdf->cam.z += 0.3;
	if (keycode == 89 && fdf->cam.view == 'v')
		fdf->cam.z -= 0.3;
}

int				events_keyboard(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		ft_close(fdf);
	if (keycode == 69 || keycode == 24 || keycode == 78 || keycode == 27)
		zoom(keycode, fdf);
	if (keycode == 0 || keycode == 123 || keycode == 2 || keycode == 124 ||
			keycode == 1 || keycode == 125 || keycode == 13 || keycode == 126)
		view_move(keycode, fdf);
	if (keycode == 86 || keycode == 88 || keycode == 91 ||
			keycode == 84 || keycode == 92 || keycode == 89)
		rotation(keycode, fdf);
	if (keycode == 34)
		fdf->cam.view = 'i';
	if (keycode == 9)
		fdf->cam.view = 'v';
	ft_bzero(fdf->cfg.img, WIN_H * WIN_W * 4);
	draw_map(fdf->map, fdf->cam, fdf->cfg);
	put_wdw(fdf->cfg.connect, fdf->cfg.window, fdf->cfg.img_con, fdf->cam.view);
	return (0);
}

int				ft_close(t_fdf *fdf)
{
	cleaner(NULL, NULL, (void****)&fdf->map.cords);
	exit(0);
	return (0);
}
