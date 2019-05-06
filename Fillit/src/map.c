/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:31:07 by pdiedra           #+#    #+#             */
/*   Updated: 2019/05/06 15:39:58 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				upd_map(char **map, char repl, char smpl)
{
	int i;
	int j;

	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == repl)
				map[j][i] = smpl;
			i++;
		}
		j++;
	}
	return (0);
}

char			**new_map(const int size)
{
	char	**map;
	int		j;

	if ((map = (char**)malloc(sizeof(char*) * size + 1)) == NULL)
		return (NULL);
	j = 0;
	while (j < size)
	{
		if ((map[j] = ft_strnew(size)) == NULL)
			return (free_array(&map));
		ft_memset(map[j], '.', size);
		j++;
	}
	map[j] = NULL;
	return (map);
}

char			**stretch_map(char ***map)
{
	size_t	size;
	char	**new_map;
	int		i;

	size = ft_strlen((*map)[0]);
	if (!(new_map = (char**)malloc(sizeof(char*) * (size + 2))))
		return (free_array(map));
	i = 0;
	while ((*map)[i] != NULL)
	{
		if (!(new_map[i] = ft_strjoin((*map)[i], ".")))
		{
			free_array(&new_map);
			return (free_array(map));
		}
		free((*map)[i]);
		i++;
	}
	new_map[i] = ft_strnew(size + 1);
	new_map[i] = ft_memset(new_map[i], '.', size + 1);
	new_map[i + 1] = NULL;
	free(*map);
	return (new_map);
}

static int		tetr_to_cord(t_cord cord, t_tetr *tetr, char **map)
{
	t_cord c;

	c.y = 0;
	while (tetr->map[c.y] != NULL)
	{
		c.x = 0;
		while (tetr->map[c.y][c.x] != 0)
		{
			if (map[c.y + cord.y] && map[c.y + cord.y][c.x + cord.x] &&
			map[c.y + cord.y][c.x + cord.x] == '.')
				map[c.y + cord.y][c.x + cord.x] = tetr->map[c.y][c.x];
			else if (map[c.y + cord.y] && map[c.y + cord.y][c.x + cord.x] &&
			map[c.y + cord.y][c.x + cord.x] != '.'
			&& tetr->map[c.y][c.x++] == '.')
				continue ;
			else
				return (upd_map(map, tetr->let, '.'));
			c.x++;
		}
		c.y++;
	}
	tetr->cord = cord;
	return (1);
}

int				tetr_to_map(t_tetr *tetr, char **map)
{
	t_cord cord;

	cord.x = tetr->cord.x;
	cord.y = tetr->cord.y;
	if (cord.x + cord.y > 0)
	{
		upd_map(map, tetr->let, '.');
		if (next_cord(&cord, map) == 0)
			return (0);
	}
	while (map[cord.y] != NULL)
	{
		while (map[cord.y][cord.x] != 0)
		{
			if (tetr_to_cord(cord, tetr, map) == 1)
				return (1);
			cord.x++;
		}
		cord.x = 0;
		cord.y++;
	}
	return (0);
}
