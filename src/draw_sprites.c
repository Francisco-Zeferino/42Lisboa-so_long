/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:38:11 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/07/28 15:58:46 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_img(t_map *map)
{
	int	width;
	int	height;

	map->g_open_exit = mlx_xpm_file_to_image(
		map->mlx,
		"sprites/open_exit.xpm",
		&width,
		&height);
	map->g_collect = mlx_xpm_file_to_image(
		map->mlx,
		"sprites/collect.xpm",
		&width,
		&height);
	map->g_player_up = mlx_xpm_file_to_image(
		map->mlx,
		"sprites/p_up.xpm",
		&width,
		&height);
	map->g_player_left = mlx_xpm_file_to_image(
		map->mlx,
		"sprites/p_left.xpm",
		&width,
		&height);
	map->g_player_down = mlx_xpm_file_to_image(
		map->mlx,
		"sprites/p_down.xpm",
		&width,
		&height);
	map->g_player_right = mlx_xpm_file_to_image(
		map->mlx,
		"sprites/p_right.xpm",
		&width,
		&height);
	map->g_wall = mlx_xpm_file_to_image(
		map->mlx,
		"sprites/wall.xpm",
		&width,
		&height);
	map->g_exit = mlx_xpm_file_to_image(
		map->mlx,
		"sprites/exit.xpm",
		&width,
		&height);
	map->g_floor = mlx_xpm_file_to_image(
		map->mlx,
		"sprites/floor.xpm",
		&width,
		&height);
}

void	put_img(t_map *map, int x, int y)
{
	if (map->map_arr[y][x] == 'P')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->g_player, x * 32, y
				* 32);
	if (map->map_arr[y][x] == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->g_collect, x * 32,
				y * 32);
	if (map->map_arr[y][x] == '0')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->g_floor, x * 32, y
				* 32);
	if (map->map_arr[y][x] == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->num_colect == 0 ? map->g_open_exit : map->g_exit, x * 32, y
				* 32);
	if (map->map_arr[y][x] == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->g_wall, x * 32, y
				* 32);
}

void	select_img(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map_arr[y])
	{
		x = 0;
		while (map->map_arr[y][x])
		{
			put_img(map, x, y);
			x++;
		}
		y++;
	}
}
