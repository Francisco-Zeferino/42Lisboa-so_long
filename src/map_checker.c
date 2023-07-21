/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:57:55 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/07/21 11:35:32 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map(char *line, t_map *map)
{
	int	i;
	int	ln_checker;

	ln_checker = ft_strlen(line);
	i = 0;
	if (map->map_width == ln_checker)
	{
		if (line[0] == '1' && line[i] == '1')
			return (1);
		else
			error_msg();
	}
	else
		error_msg();
	return (0);
}

void	check_limits(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_width)
	{
		if (map->map_arr[0][i] == '1' && map->map_arr[map->map_height
			- 1][i] == '1')
			i++;
		else
			error_msg();
	}
}

void	read_map(t_map *map, char *file_path)
{
	int		fd;
	char	*acc;
	char	*line;
	int		i;

	map = ft_calloc(1, sizeof(t_map));
	acc = NULL;
	i = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		error_msg();
	while (1)
	{
		line = get_next_line(fd);
		if (!save_map(&acc, line))
			break ;
	}
	close(fd);
	map->map_arr = ft_split(acc, '\n');
	map->map_width = ft_strlen(map->map_arr[0]);
	while (map->map_arr[i])
	{
		valid_map(map->map_arr[i], map);
		i++;
	}
	map->map_height = i;
	check_limits(map);
	store_info(map);
	if (valid_map_paths(map) == 0)
		error_msg();
	free(map->map_arr);
	free(map);
}
