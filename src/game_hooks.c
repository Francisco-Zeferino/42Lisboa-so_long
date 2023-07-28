/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:44:58 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/07/28 14:30:04 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exec_w(t_map *map)
{
	int	y;
	int	x;

	printf("Exec w\n");
	y = map->player_y;
	x = map->player_x;
	if (map->map_arr[y - 1][x] == '1' || (map->map_arr[y - 1][x] == 'E'
			&& map->num_colect > 0))
		return ;
	if (map->map_arr[y - 1][x] == 'C')
		map->num_colect--;
	if (map->num_colect == 0 && map->map_arr[y - 1][x] == 'E')
		exit(0);
	map->map_arr[y - 1][x] = 'P';
	map->map_arr[y][x] = '0';
	map->g_player = map->g_player_up;
	select_img(map);
	map->player_y--;
}

void	exec_a(t_map *map)
{
	int	y;
	int	x;

	printf("Exec a\n");
	y = map->player_y;
	x = map->player_x;
	if (map->map_arr[y][x - 1] == '1' || (map->map_arr[y][x - 1] == 'E'
			&& map->num_colect > 0))
		return ;
	if (map->map_arr[y][x - 1] == 'C')
		map->num_colect--;
	if (map->num_colect == 0 && map->map_arr[y][x - 1] == 'E')
		exit(0);
	map->map_arr[y][x - 1] = 'P';
	map->map_arr[y][x] = '0';
	map->g_player = map->g_player_left;
	select_img(map);
	map->player_x--;
}

void	exec_s(t_map *map)
{
	int	y;
	int	x;

	printf("Exec s\n");
	y = map->player_y;
	x = map->player_x;
	if (map->map_arr[y + 1][x] == '1' || (map->map_arr[y + 1][x] == 'E'
			&& map->num_colect > 0))
		return ;
	if (map->map_arr[y + 1][x] == 'C')
		map->num_colect--;
	if (map->num_colect == 0 && map->map_arr[y + 1][x] == 'E')
		exit(0);
	map->map_arr[y + 1][x] = 'P';
	map->map_arr[y][x] = '0';
	map->g_player = map->g_player_down;
	select_img(map);
	map->player_y++;
}

void	exec_d(t_map *map)
{
	int	y;
	int	x;

	printf("Exec d\n");
	y = map->player_y;
	x = map->player_x;
	if (map->map_arr[y][x + 1] == '1' || (map->map_arr[y][x + 1] == 'E'
			&& map->num_colect > 0))
		return ;
	if (map->map_arr[y][x + 1] == 'C')
		map->num_colect--;
	if (map->num_colect == 0 && map->map_arr[y][x + 1] == 'E')
		exit(0);
	map->map_arr[y][x + 1] = 'P';
	map->map_arr[y][x] = '0';
	map->g_player = map->g_player_right;
	select_img(map);
	map->player_x++;
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 119)
		exec_w(map);
	if (keycode == 97)
		exec_a(map);
	if (keycode == 115)
		exec_s(map);
	if (keycode == 100)
		exec_d(map);
	if (keycode == 65307)
		exit(0);
	return (0);
}
