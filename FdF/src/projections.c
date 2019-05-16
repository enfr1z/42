/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:22:18 by vsanta            #+#    #+#             */
/*   Updated: 2019/05/14 21:09:38 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_cord	cord_iso(t_cord cord)
{
	t_cord new_cord;

	new_cord.x = ((cord.x - cord.y) * cos(0.523599));
	new_cord.y = (-cord.z + (cord.x + cord.y) * sin(0.523599));
	new_cord.color = cord.color;
	return (new_cord);
}

static t_cord	cord_scale(t_cord cord, t_cam cam, t_map map)
{
	t_cord new_cord;

	new_cord.x = cord.x * cam.scale - ((map.w - 1) / 2) * cam.scale;
	new_cord.y = cord.y * cam.scale - ((map.h - 1) / 2) * cam.scale;
	new_cord.z = cord.z * cam.scale;
	new_cord.color = cord.color;
	return (new_cord);
}

static t_cord	cord_move(t_cord cord, t_cam cam)
{
	t_cord new_cord;

	new_cord.x = new_cord.x + cam.s_x + WIN_W / 2;
	new_cord.y = new_cord.y + cam.s_y + WIN_H / 2;
	new_cord.color = cord.color;
	return (new_cord);
}

t_cord			proj(t_cord cord, t_cam cam, t_map map)
{
	t_cord new_cord;

	new_cord = cord_scale(cord, cam, map);
	if (cam.view == 'v')
	{
		new_cord = rotate_x(new_cord, cam);
		new_cord = rotate_y(new_cord, cam);
		new_cord = rotate_z(new_cord, cam);
	}
	else
		new_cord = cord_iso(new_cord);
	new_cord = cord_move(new_cord, cam);
	return (new_cord);
}
