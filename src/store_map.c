/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:01:26 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/07/21 11:33:44 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	save_map(char **acc, char *line)
{
	char	*new;

	if (!line || *line == '\0' || *line == '\n')
	{
		free(line);
		return (0);
	}
	new = ft_strjoin(*acc, line);
	*acc = new;
	free(line);
	return (1);
}

void	save_coordenates(t_map *map, char obj, int x, int y)
{
	if (obj == 'P')
	{
		map->player_x = x;
		map->player_y = y;
		map->num_players += 1;
	}
	if (obj == 'E')
	{
		map->exit_x = x;
		map->exit_y = y;
		map->num_exit += 1;
	}
}

void	store_info(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_arr[i])
	{
		j = 0;
		while (map->map_arr[i][j])
		{
			if (map->map_arr[i][j] == 'P')
				save_coordenates(map, 'P', j, i);
			else if (map->map_arr[i][j] == 'E')
				save_coordenates(map, 'E', j, i);
			else if (map->map_arr[i][j] == 'C')
				map->num_colect += 1;
			else if (map->map_arr[i][j] != '1' && map->map_arr[i][j] != '0')
				error_msg();
			j++;
		}
		i++;
	}
	if (map->num_players > 1 || map->num_exit > 1)
		error_msg();
}
