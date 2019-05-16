/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:13:02 by vsanta            #+#    #+#             */
/*   Updated: 2019/05/14 18:37:53 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		delta_sign(t_cfg *cfg, t_draw *d)
{
	cfg->drw_ln.delta_x = ft_abs(d->e.x - d->s.x);
	cfg->drw_ln.delta_y = ft_abs(d->e.y - d->s.y);
	cfg->drw_ln.sign_x = d->s.x < d->e.x ? 1 : -1;
	cfg->drw_ln.sign_y = d->s.y < d->e.y ? 1 : -1;
}

static void		draw_line(t_draw d, t_cfg cfg)
{
	t_draw tmp;

	tmp = d;
	delta_sign(&cfg, &d);
	cfg.drw_ln.error = cfg.drw_ln.delta_x - cfg.drw_ln.delta_y;
	if (d.e.x >= 0 && d.e.x < WIN_W && d.e.y >= 0 && d.e.y < WIN_H)
		cfg.img[d.e.y * WIN_W + d.e.x] = cord_color(d.e, tmp.s, tmp.e);
	while (d.s.x != d.e.x || d.s.y != d.e.y)
	{
		if (d.s.x >= 0 && d.s.x < WIN_W && d.s.y >= 0 && d.s.y < WIN_H)
			cfg.img[d.s.y * WIN_W + d.s.x] = cord_color(d.s, tmp.s, tmp.e);
		cfg.drw_ln.error2 = cfg.drw_ln.error * 2;
		if (cfg.drw_ln.error2 > -cfg.drw_ln.delta_y)
		{
			cfg.drw_ln.error -= cfg.drw_ln.delta_y;
			d.s.x += cfg.drw_ln.sign_x;
		}
		if (cfg.drw_ln.error2 < cfg.drw_ln.delta_x)
		{
			cfg.drw_ln.error += cfg.drw_ln.delta_x;
			d.s.y += cfg.drw_ln.sign_y;
		}
	}
}

void			draw_map(t_map map, t_cam cam, t_cfg cfg)
{
	int		x;
	int		y;
	t_draw	d;

	y = 0;
	while (map.cords[y])
	{
		x = 0;
		while (map.cords[y][x])
		{
			d.s = proj(*(map.cords[y][x]), cam, map);
			if (map.cords[y][x + 1])
			{
				d.e = proj(*(map.cords[y][x + 1]), cam, map);
				draw_line(d, cfg);
			}
			if (map.cords[y + 1])
			{
				d.e = proj(*(map.cords[y + 1][x]), cam, map);
				draw_line(d, cfg);
			}
			x++;
		}
		y++;
	}
}
