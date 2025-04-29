/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:41:54 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/16 13:26:23 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	s1;
	size_t	s2;

	s1 = ft_strlen(src);
	s2 = ft_strlen(dst);
	if (s2 >= siz)
	{
		s2 = siz;
		return (s1 + siz);
	}
	if (s1 < (siz - s2))
		ft_memcpy(dst + s2, src, s1 + 1);
	else
	{
		ft_memcpy(dst + s2, src, siz - s2 - 1);
		dst[siz - 1] = 0;
	}
	return (s1 + s2);
}
