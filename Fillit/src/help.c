/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:55:57 by pdiedra           #+#    #+#             */
/*   Updated: 2019/05/02 18:53:04 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**free_array(char ***array)
{
	int	i;

	i = 0;
	while ((*array)[i])
	{
		free((*array)[i]);
		(*array)[i] = NULL;
		i++;
	}
	if (*array)
	{
		free(*array);
		*array = NULL;
	}
	return (NULL);
}

int		free_tetr_list(t_tetr **tetr)
{
	t_tetr	*next;

	while (*tetr)
	{
		free_array(&(*tetr)->map);
		next = (*tetr)->next;
		free(*tetr);
		(*tetr) = next;
	}
	return (0);
}

int		min_map_size(int count_tetr)
{
	int	size;
	int	i;

	i = 0;
	while ((size = ft_sqrt(count_tetr * 4 + i)) == 0)
		i++;
	return (size);
}

int		next_cord(t_cord *cord, char **map)
{
	int	x;
	int y;

	y = cord->y;
	x = cord->x;
	if (map[y][x + 1] == '\0' && y == x)
		return (0);
	if (map[y][x + 1] == '\0')
	{
		cord->y = y + 1;
		cord->x = 0;
		return (1);
	}
	cord->y = y;
	cord->x = x + 1;
	return (1);
}

void	remove_tetr(char **map, t_tetr *tetr)
{
	upd_map(map, tetr->let, '.');
	tetr->cord.x = 0;
	tetr->cord.y = 0;
}
