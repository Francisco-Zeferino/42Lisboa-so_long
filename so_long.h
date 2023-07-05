/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:58:03 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/07/05 15:40:27 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}			t_data;

typedef struct map_data
{
	char 		**map_arr;
	int		num_colect;
	int		num_players;
	int		num_exit;
}			t_map;

void		check_map(char *file_path);
int			map_validator(char *line, int line_len, t_map *map);
void		error_msg(void);