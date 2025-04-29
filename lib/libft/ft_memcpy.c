/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:29:34 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/16 13:24:36 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	if (!dest && !src)
		return (0);
	pdest = (unsigned char *)(dest);
	psrc = (unsigned char *)(src);
	while (n)
	{
		*pdest++ = *psrc++;
		n--;
	}
	return (dest);
}
