/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:20:14 by vsanta            #+#    #+#             */
/*   Updated: 2019/05/14 21:20:11 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include "libft.h"
# include "get_next_line.h"

# define WIN_W 1920
# define WIN_H 1080
# define BASE_COL 0xFFFFFF
# define TOP_COL 0x590000
# define BOT_COL 0x07EB96
# define RED 0xFF0000
# define WIN_TITLE "FdF"

typedef struct	s_cord
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_cord;

typedef struct	s_cam
{
	double		x;
	double		y;
	double		z;
	int			scale;
	int			s_x;
	int			s_y;
	char		view;
}				t_cam;

typedef struct	s_draw
{
	t_cord		s;
	t_cord		e;
}				t_draw;

typedef struct	s_map
{
	int			w;
	int			h;
	int			min_d;
	int			max_d;
	t_cord		***cords;
}				t_map;

typedef struct	s_drw_ln
{
	int			delta_x;
	int			delta_y;
	int			sign_x;
	int			sign_y;
	int			error;
	int			error2;
}				t_drw_ln;

typedef struct	s_cfg
{
	void		*connect;
	void		*window;
	void		*img_con;
	int			*img;
	int			bpp;
	int			size_l;
	int			endian;
	t_drw_ln	drw_ln;
}				t_cfg;

typedef struct	s_fdf
{
	t_map		map;
	t_cam		cam;
	t_cfg		cfg;
	char		*str;
}				t_fdf;

typedef struct	s_rdr
{
	int			fd;
	int			i;
	int			gnl;
	int			w_count;
	char		*line;
	char		**split_line;
}				t_rdr;

int				events_keyboard(int keycode, t_fdf *fdf);
int				ft_close(t_fdf *fdf);
int				reader(char *file_name, t_map *map);
int				cord_color(t_cord current, t_cord start, t_cord end);
int				cleaner(void **ar1, void ***ar2, void ****ar3);
void			fill_map(t_map *map);
void			draw_map(t_map map, t_cam cam, t_cfg cfg);
void			put_wdw(void *connect, void *window, void *img, char mode);
t_cord			rotate_x(t_cord cord, t_cam cam);
t_cord			rotate_y(t_cord cord, t_cam cam);
t_cord			rotate_z(t_cord cord, t_cam cam);
t_cord			proj(t_cord cord, t_cam cam, t_map map);

#endif
