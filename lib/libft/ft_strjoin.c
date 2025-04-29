/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:41:54 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/29 13:25:41 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l_s1;
	int		l_s2;
	char	*result;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	result = ft_calloc((l_s1 + l_s2 + 1), sizeof(char));
	if (!result)
		return (0);
	ft_strlcpy(result, s1, l_s1 + 1);
	ft_strlcat(result, s2, l_s1 + l_s2 + 1);
	return (result);
}
