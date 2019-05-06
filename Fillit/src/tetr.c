/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:54:30 by vsanta            #+#    #+#             */
/*   Updated: 2019/05/02 18:40:41 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			empty_col(char *buf, int i)
{
	if (buf[i] == '.' && buf[i + 5] == '.' &&
		buf[i + 10] == '.' && buf[i + 15] == '.')
		return (1);
	return (0);
}

static t_tetrmap	set_tetrmap_param(char *buf)
{
	t_tetrmap	tetrmap;
	int			i;

	i = 0;
	tetrmap.start = -1;
	tetrmap.end = -1;
	while (i < 4)
	{
		if (tetrmap.start == -1 && empty_col(buf, i) == 0)
			tetrmap.start = i;
		if (tetrmap.start != -1 && empty_col(buf, i) == 1)
		{
			tetrmap.end = i - 1;
			break ;
		}
		i++;
	}
	if (tetrmap.end == -1)
		tetrmap.end = 3;
	return (tetrmap);
}

static char			**get_tetrmap(char *buf)
{
	t_tetrmap	tetrmap;
	int			i;
	int			j;
	char		*tmp;

	tetrmap = set_tetrmap_param(buf);
	i = 0;
	j = 0;
	if ((tetrmap.map = (char**)malloc(sizeof(char*) * 5)) == NULL)
		return (NULL);
	while (i < 20)
	{
		if ((tmp = ft_strsub(buf, i + tetrmap.start,
					tetrmap.end - tetrmap.start + 1)) == NULL)
			return (NULL);
		if (ft_strchr(tmp, '#'))
			tetrmap.map[j++] = tmp;
		else
			free(tmp);
		i = i + 5;
	}
	tetrmap.map[j] = NULL;
	return (tetrmap.map);
}

static t_tetr		*create_tetr(char *buf, int tetr_index)
{
	t_tetr *tmp;

	if ((tmp = (t_tetr*)malloc(sizeof(t_tetr))) == NULL)
		return (NULL);
	if ((tmp->map = get_tetrmap(buf)) == NULL)
		return (NULL);
	tmp->let = 65 + tetr_index;
	tmp->cord.x = 0;
	tmp->cord.y = 0;
	upd_map(tmp->map, '#', tmp->let);
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

int					list_push_tetr(t_tetr **tetr, char *buf, int tetr_index)
{
	t_tetr *tmp;

	tmp = *tetr;
	if (*tetr)
	{
		while (tmp->next)
			tmp = tmp->next;
		if ((tmp->next = create_tetr(buf, tetr_index)) == NULL)
			return (0);
		tmp->next->prev = tmp;
	}
	else
	{
		if ((*tetr = create_tetr(buf, tetr_index)) == NULL)
			return (0);
	}
	return (1);
}
