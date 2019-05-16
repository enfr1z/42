/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:30:47 by vsanta            #+#    #+#             */
/*   Updated: 2019/05/14 16:55:59 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static int		get_color(int s_color, int e_color, double percentage)
{
	int	red;
	int	green;
	int	blue;

	red = get_light((s_color >> 16) & 0xFF, (e_color >> 16) & 0xFF, percentage);
	green = get_light((s_color >> 8) & 0xFF, (e_color >> 8) & 0xFF, percentage);
	blue = get_light(s_color & 0xFF, e_color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int				cord_color(t_cord current, t_cord start, t_cord end)
{
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (ft_abs(start.x - end.x) > ft_abs(start.y - end.y))
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	return (get_color(start.color, end.color, percentage));
}

void			fill_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->cords[y])
	{
		x = 0;
		while (map->cords[y][x])
		{
			if (map->cords[y][x]->z > 0 && map->cords[y][x]->color == 0)
			{
				map->cords[y][x]->color = get_color(BASE_COL, TOP_COL,
				percent(0, ft_abs(map->max_d), map->cords[y][x]->z));
			}
			else if (map->cords[y][x]->z < 0 && map->cords[y][x]->color == 0)
			{
				map->cords[y][x]->color = get_color(BASE_COL, BOT_COL,
				percent(0, ft_abs(map->max_d), ft_abs(map->cords[y][x]->z)));
			}
			else if (map->cords[y][x]->color == 0)
				map->cords[y][x]->color = BASE_COL;
			x++;
		}
		y++;
	}
}
