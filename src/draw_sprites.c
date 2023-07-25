/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:38:11 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/07/25 14:45:17 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	select_img(t_map *map)
{
	void	*ptr;
	int		y;
	int		x;
	int		width;
	int		height;

	y = 0;
	while (map->map_arr[y])
	{
		x = 0;
		while (map->map_arr[y][x])
		{
			ptr = NULL;
			if (map->map_arr[y][x] == 'C')
				ptr = mlx_xpm_file_to_image(map->mlx, "sprites/health.xpm",
						&width, &height);
			if (map->map_arr[y][x] == 'P')
				ptr = mlx_xpm_file_to_image(map->mlx, "sprites/walk_down.xpm",
						&width, &height);
			if (ptr)
				mlx_put_image_to_window(map->mlx, map->mlx_win, ptr, x * 32, y
						* 32);
			x++;
		}
		y++;
	}
}
