/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:12:13 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/07/27 14:39:33 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, int *counter)
{
	if (map[y][x] == 'C' || map[y][x] == 'E')
		*counter += 1;
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return ;
	}
	map[y][x] = 'F';
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'F')
		flood_fill(map, x + 1, y, counter);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'F')
		flood_fill(map, x - 1, y, counter);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'F')
		flood_fill(map, x, y + 1, counter);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'F')
		flood_fill(map, x, y - 1, counter);
}

int	valid_map_paths(t_map *map)
{
	char	**tmp_map;
	int		i;
	int		counter;

	i = 0;
	tmp_map = (char **)malloc(sizeof(char *) * (map->map_height + 1));
	while (map->map_arr[i])
	{
		tmp_map[i] = ft_strdup(map->map_arr[i]);
		i++;
	}
	tmp_map[i] = NULL;
	counter = 0;
	flood_fill(tmp_map, map->player_x, map->player_y, &counter);
	if (counter == (map->num_exit + map->num_colect))
	{
		free(tmp_map);
		return (1);
	}
	else
	{
		free(tmp_map);
		return (0);
	}
}
