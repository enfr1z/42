/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:43:47 by pdiedra           #+#    #+#             */
/*   Updated: 2019/05/14 20:01:51 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_wdw(void *connect, void *window, void *img, char mode)
{
	mlx_put_image_to_window(connect, window, img, 0, 0);
	mlx_string_put(connect, window, 10, 10, BASE_COL, "Zoom: +/-");
	mlx_string_put(connect, window, 70, 10, 0xFFFF, "+/-");
	mlx_string_put(connect, window, 10, 25, BASE_COL, "---------------------");
	mlx_string_put(connect, window, 10, 50, BASE_COL, "Move:");
	mlx_string_put(connect, window, 70, 40, 0xFFFF, "W, A, S, D");
	mlx_string_put(connect, window, 70, 60, 0xFFFF, "Lft, Up, Rght, Dwn");
	mlx_string_put(connect, window, 10, 75, BASE_COL, "---------------------");
	mlx_string_put(connect, window, 10, 110, BASE_COL, "Rotate:");
	mlx_string_put(connect, window, 90, 90, 0xFFFF, "X: 4, 6");
	mlx_string_put(connect, window, 90, 110, 0xFFFF, "Y: 8, 2");
	mlx_string_put(connect, window, 90, 130, 0xFFFF, "Z: 7, 9");
	mlx_string_put(connect, window, 10, 145, BASE_COL, "---------------------");
	mlx_string_put(connect, window, 10, 170, BASE_COL, "Change mode:");
	mlx_string_put(connect, window, 140, 160, 0xFFFF, "Iso: I");
	mlx_string_put(connect, window, 140, 180, 0xFFFF, "3D: V");
	mlx_string_put(connect, window, 10, 195, BASE_COL, "---------------------");
	mlx_string_put(connect, window, 10, 210, BASE_COL, "Current mode:");
	if (mode == 'i')
		mlx_string_put(connect, window, 150, 210, 0xFF00FF, "Isometria");
	if (mode == 'v')
		mlx_string_put(connect, window, 150, 210, 0xFF00FF, "3D");
	mlx_string_put(connect, window, 10, 225, BASE_COL, "---------------------");
	mlx_string_put(connect, window, 10, 240, RED, "Made by pdiedra & vsanta");
	mlx_string_put(connect, window, 10, 255, BASE_COL, "---------------------");
}
