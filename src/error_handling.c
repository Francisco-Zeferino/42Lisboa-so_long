/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:26:22 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/07/28 16:12:28 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	check_ac(int ac)
{
	if (ac == 2)
		return ;
	else if (ac > 2)
	{
		write(2, "Too many aguments\n", 18);
		exit(0);
	}
	else
	{
		write(2, "Please choose the map\n", 22);
		exit(0);
	}
}

void	check_file_path(char *file_path)
{
	char	*dot;

	dot = ft_strrchr(file_path, '.');
	if (!dot)
		error_msg();
	if (ft_strncmp(".ber", dot,
			5) != 0)
		error_msg();
}

void	error_checks(int ac, char *file_path)
{
	check_ac(ac);
	check_file_path(file_path);
}
