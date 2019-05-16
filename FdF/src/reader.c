/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:12:37 by vsanta            #+#    #+#             */
/*   Updated: 2019/05/14 21:26:09 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				cleaner(void **ar1, void ***ar2, void ****ar3)
{
	int i;

	i = 0;
	if (ar1 && *ar1)
		free(*ar1);
	if (ar2 && **ar2)
		ft_free_array(ar2);
	if (ar3 && ***ar3)
	{
		while ((*ar3)[i])
		{
			ft_free_array(&((*ar3)[i]));
			i++;
		}
		free(*ar3);
		*ar3 = NULL;
	}
	return (0);
}

static t_cord	**new_map_line(char **split_line, int i, t_map *map)
{
	int		j;
	int		k;
	t_cord	**map_line;

	if ((map_line = (t_cord**)malloc(sizeof(t_cord*) * (map->w + 1))) == NULL)
		return (NULL);
	j = 0;
	while (split_line[j])
	{
		k = 0;
		if ((map_line[j] = (t_cord*)malloc(sizeof(t_cord))) == NULL)
			return ((cleaner(NULL, (void***)&map_line, NULL)) == 0 ? NULL : 0);
		map_line[j]->x = j;
		map_line[j]->y = i;
		map_line[j]->z = ft_atoi(split_line[j]);
		map->max_d = map_line[j]->z > map->max_d ? map_line[j]->z : map->max_d;
		map->min_d = map_line[j]->z < map->min_d ? map_line[j]->z : map->min_d;
		map_line[j]->color = 0;
		while (split_line[j][k])
			if (split_line[j][k++] == ',' && split_line[j][k + 2])
				map_line[j]->color = ft_atoi_base(&split_line[j][k + 2], 16);
		j++;
	}
	map_line[j] = NULL;
	return (map_line);
}

static int		push_line_to_map(t_map *map, char **split_line, int i)
{
	t_cord	***new_cords;
	int		j;

	if (split_line == NULL)
		return (0);
	if ((new_cords = (t_cord***)malloc(sizeof(t_cord**) * (i + 2))) == NULL)
		return (0);
	j = 0;
	while (map->cords != NULL && map->cords[j] != NULL)
	{
		new_cords[j] = map->cords[j];
		j++;
	}
	if ((new_cords[j] = new_map_line(split_line, i, map)) == NULL)
		return (cleaner(NULL, NULL, (void****)&new_cords));
	new_cords[j + 1] = NULL;
	map->cords = new_cords;
	return (1);
}

int				reader(char *file_name, t_map *map)
{
	t_rdr rdr;

	if ((rdr.fd = open(file_name, O_RDONLY)) < 0)
		return (0);
	rdr.i = 0;
	while ((rdr.gnl = get_next_line(rdr.fd, &rdr.line)) == 1)
	{
		if (rdr.i == 0)
			map->w = ft_w_count(rdr.line, 32);
		rdr.w_count = (rdr.i == 0) ? map->w : ft_w_count(rdr.line, 32);
		if (rdr.w_count != map->w)
			return (0);
		rdr.split_line = ft_strsplit(rdr.line, 32);
		if ((push_line_to_map(map, rdr.split_line, rdr.i++) == 0))
			rdr.gnl = -1;
		cleaner((void**)&rdr.line, (void***)&rdr.split_line, NULL);
	}
	if (rdr.gnl < 0)
		return (cleaner(NULL, NULL, (void****)&map->cords));
	map->h = rdr.i;
	fill_map(map);
	close(rdr.fd);
	return (1);
}
