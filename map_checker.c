/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:57:55 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/07/05 15:53:06 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	objs_validator(char *line, t_map *map)
{
	int i;
	
	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			map->num_players += 1;
		if (line[i] == 'E')
			map->num_exit += 1;
		if (line[i] == 'C')
			map->num_colect += 1;
		i++;
	}
	if(map->num_players > 1 || map->num_exit > 1)
		return 0;
	else
		return 1;
}

int	map_validator(char *line, int line_len, t_map *map)
{
	int	i;

	i = ft_strlen(line);
	if (i > 0 && line[i - 1] == '\n')
		line[--i] = '\0';
	if (!line)
		return (0);
	else if (line[0] == '1' && line[i - 1] == '1')
	{
		if(objs_validator(line, map) == 1 && (line_len - 1) == i)
		{
			free(line);
			return (1);
		}
		else
			return 0;
	}
	else
		return (0);
}

void	check_map(char *file_path)
{
	int		fd;
	int		i;
	char	*line;

	
	i = 0;
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	i = ft_strlen(line);
	while (line)
	{
		if (map_validator(line, i, map) == 1)
			line = get_next_line(fd);
		else
		{
			free(line);
			error_msg();
		}
	}
}