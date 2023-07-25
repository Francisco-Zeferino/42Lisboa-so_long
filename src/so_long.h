/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:58:03 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/07/25 13:55:43 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../get_next_line/get_next_line.h"
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
	char	**map_arr;
	int		map_height;
	int		map_width;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		num_colect;
	int		num_players;
	int		num_exit;
	void	*mlx;
	void	*mlx_win;
}			t_map;

int			save_map(char **acc, char *line);
void		read_map(t_map *map, char *file_path);
void		store_info(t_map *map);
void		error_msg(void);
char		*ft_strjoin(char const *s1, char const *s2);
void		check_ac(int ac);
int			valid_map_paths(t_map *map);
void		init_game(t_map *map);
void		flood_fill(char **map, int x, int y, int *counter);
void		check_file_path(char *file_path);
void		error_checks(int ac, char *file_path);
void		select_img(t_map *map);
