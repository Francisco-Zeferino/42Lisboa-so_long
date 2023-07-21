/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:32:24 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/07/21 11:11:43 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		len_str1;
	int		len_str2;
	int		total_len;

	len_str1 = ft_strlen(s1);
	len_str2 = ft_strlen(s2);
	total_len = len_str1 + len_str2;
	new_str = (char *)malloc(total_len + 1);
	if (new_str == NULL)
	{
		return (0);
	}
	ft_strlcpy(new_str, s1, len_str1 + 1);
	ft_strlcpy(new_str + len_str1, s2, len_str2 + 1);
	return (new_str);
}
