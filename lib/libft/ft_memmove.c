/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:29:36 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/16 13:24:52 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*psrc;
	char	*pdst;

	if (!dst && !src)
		return (0);
	psrc = (char *)src;
	pdst = (char *)dst;
	if (pdst > psrc)
		while (len-- > 0)
			pdst[len] = psrc[len];
	else
	{
		ft_memcpy(pdst, psrc, len);
	}
	return (dst);
}
