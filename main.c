/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:45:08 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/07/05 15:53:11 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_map	*map;
	int fd;
	
	map = malloc(sizeof(t_map));
	map->num_colect = 0;
	map->num_players = 0;
	map->num_exit = 0;

	fd = open("maps/map1.ber", O_RDONLY);
	check_map();
}
