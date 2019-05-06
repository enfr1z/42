/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 19:50:24 by pdiedra           #+#    #+#             */
/*   Updated: 2019/05/01 16:30:51 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MAX_TETR 26
# include "libft.h"
# include <fcntl.h>

typedef struct			s_tetrmap
{
	int					start;
	int					end;
	char				**map;
}						t_tetrmap;

typedef struct			s_cord
{
	int					x;
	int					y;
}						t_cord;

typedef struct			s_tetr
{
	t_cord				cord;
	char				let;
	char				**map;
	struct s_tetr		*next;
	struct s_tetr		*prev;
}						t_tetr;

char					**free_array(char ***array);
int						free_tetr_list(t_tetr **tetr);
int						min_map_size(int count_tetr);
int						next_cord(t_cord *cord, char **map);
void					remove_tetr(char **map, t_tetr *tetr);
int						tetr_to_map(t_tetr *tetr, char **map);
char					**stretch_map(char ***map);
char					**new_map(const int size);
int						upd_map(char **map, char repl, char smpl);
int						list_push_tetr(t_tetr **tetr, char *buf,
						int tetr_index);
int						valid_tetr(const char *str, int ret);

#endif
