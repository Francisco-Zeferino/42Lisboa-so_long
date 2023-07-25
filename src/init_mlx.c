/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:31:56 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/07/25 14:09:43 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, map->map_width * 32, map->map_height
			* 32, "so_long");
	select_img(map);
	mlx_loop(map->mlx);
}
