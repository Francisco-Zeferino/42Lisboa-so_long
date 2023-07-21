/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:51:09 by marvin            #+#    #+#             */
/*   Updated: 2023/04/13 13:32:17 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int charact)
{
	if ((charact >= 'a' && charact <= 'z') || (charact >= 'A'
			&& charact <= 'Z'))
	{
		return (1);
	}
	return (0);
}
