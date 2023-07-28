/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:45:08 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/07/28 11:28:53 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	check_ac(ac);
	error_checks(ac, av[1]);
	read_map(map, av[1]);
	init_game(map);
}
