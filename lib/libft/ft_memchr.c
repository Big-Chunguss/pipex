/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:29:28 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/16 13:24:13 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	size_t			i;

	i = 0;
	ps = (unsigned char *)s;
	while (n)
	{
		if (ps[i] == (unsigned char)c)
			return ((void *)(ps + i));
		i++;
		n--;
	}
	return (0);
}
