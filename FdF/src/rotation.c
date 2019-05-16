/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:24:21 by pdiedra           #+#    #+#             */
/*   Updated: 2019/05/14 16:31:13 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cord	rotate_x(t_cord cord, t_cam cam)
{
	t_cord new_cord;

	new_cord.x = cord.x;
	new_cord.y = cord.y * cos(cam.x) + cord.z * sin(cam.x);
	new_cord.z = -cord.y * sin(cam.x) + cord.z * cos(cam.x);
	new_cord.color = cord.color;
	return (new_cord);
}

t_cord	rotate_y(t_cord cord, t_cam cam)
{
	t_cord new_cord;

	new_cord.x = cord.x * cos(cam.y) + cord.z * sin(cam.y);
	new_cord.y = cord.y;
	new_cord.z = -cord.x * sin(cam.y) + cord.z * cos(cam.y);
	new_cord.color = cord.color;
	return (new_cord);
}

t_cord	rotate_z(t_cord cord, t_cam cam)
{
	t_cord new_cord;

	new_cord.x = cord.x * cos(cam.z) - cord.y * sin(cam.z);
	new_cord.y = cord.x * sin(cam.z) + cord.y * cos(cam.z);
	new_cord.z = cord.z;
	new_cord.color = cord.color;
	return (new_cord);
}
