/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:30:53 by pdiedra           #+#    #+#             */
/*   Updated: 2019/05/06 15:55:03 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		put_error_free(int fd, t_tetr **tetr, char ***map, char *msg)
{
	if (tetr != NULL)
		free_tetr_list(tetr);
	if (map != NULL)
		free_array(map);
	if (fd > 0)
		close(fd);
	ft_putstr_fd(msg, 1);
	exit(EXIT_FAILURE);
}

static void		print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		ft_putendl(map[i++]);
}

static int		bruteforce_tetr(t_tetr *tetr, char ***map)
{
	int		tetr_ok;
	t_tetr	*cur_tetr;

	cur_tetr = tetr;
	while (cur_tetr != NULL)
	{
		tetr_ok = tetr_to_map(cur_tetr, *map);
		if (tetr_ok == 1)
		{
			cur_tetr = cur_tetr->next;
			continue ;
		}
		else if (tetr_ok == 0)
		{
			remove_tetr(*map, cur_tetr);
			cur_tetr = cur_tetr->prev;
		}
		if (cur_tetr == NULL)
		{
			if ((*map = stretch_map(map)) == NULL)
				return (0);
			bruteforce_tetr(tetr, map);
		}
	}
	return (1);
}

static int		reader(int fd, t_tetr **tetr)
{
	int		i;
	int		ret;
	int		count;
	char	buf[22];

	i = 0;
	count = 0;
	if (fd < 0)
		return (0);
	while ((ret = read(fd, buf, 21)) >= 20)
	{
		if (valid_tetr(buf, ret) == 1 && i < MAX_TETR)
		{
			if (list_push_tetr(tetr, buf, i++) == 0)
				return (free_tetr_list(tetr));
		}
		else
			return (free_tetr_list(tetr));
		count += ret;
	}
	if (count / 21 == i)
		return (free_tetr_list(tetr));
	if (ret != 0)
		return (0);
	return (i);
}

int				main(int ac, char **av)
{
	int		count_tetr;
	int		fd;
	char	**map;
	t_tetr	*tetr;

	tetr = NULL;
	if (ac != 2)
		put_error_free(-1, NULL, NULL, "usage: ./fillit [filename]\n");
	fd = open(av[1], O_RDONLY);
	if ((count_tetr = reader(fd, &tetr)) == 0)
		put_error_free(fd, NULL, NULL, "error\n");
	close(fd);
	if ((map = new_map(min_map_size(count_tetr))) == NULL)
		put_error_free(-1, &tetr, NULL, "error\n");
	if (bruteforce_tetr(tetr, &map) == 0)
		put_error_free(-1, &tetr, &map, "error\n");
	print_map(map);
	free_tetr_list(&tetr);
	free_array(&map);
	return (0);
}
