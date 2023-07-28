/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:10:11 by marvin            #+#    #+#             */
/*   Updated: 2023/07/28 16:09:19 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0 || !s1 || !s2)
	{
		return (0);
	}
	while (s1[i] != '\0' && i < n && s1[i] == s2[i])
	{
		i++;
		if (i == n)
		{
			return (0);
		}
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
