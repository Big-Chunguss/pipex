/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:16:02 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/16 14:41:00 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr_base(unsigned long long nbr, char *base, int *value,
		char type)
{
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16, base, value, type);
	ft_putchar(base[nbr % 16], value);
}

void	ft_printf_p(unsigned long long nbr, char *base, int *value, char type)
{
	if (nbr == 0)
	{
		ft_putstr("(nil)", value);
		return ;
	}
	ft_putstr("0x", value);
	ft_putnbr_base(nbr, base, value, type);
}
