/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:41:54 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/16 13:26:30 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(src);
	i = 0;
	j = 0;
	if (siz > 0)
	{
		siz--;
		while (src[j] && siz)
		{
			dst[i] = src[j];
			i++;
			j++;
			siz--;
		}
		dst[i] = 0;
	}
	return (len);
}
