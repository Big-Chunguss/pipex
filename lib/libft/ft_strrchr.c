/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:41:54 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/16 13:26:56 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	un_c;
	char			*ptr;
	int				i;

	un_c = (unsigned char)c;
	ptr = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == un_c)
			ptr = (char *)(s + i);
		i++;
	}
	if (!un_c)
		ptr = (char *)(s + i);
	return (ptr);
}
