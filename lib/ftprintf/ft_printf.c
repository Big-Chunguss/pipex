/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:16:11 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/19 16:16:13 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_args(char c, va_list args, int *value)
{
	if (c == 'c')
		ft_putchar((char)va_arg(args, int), value);
	else if (c == 's')
		ft_putstr((char *)va_arg(args, char *), value);
	else if (c == 'p')
		ft_printf_p(va_arg(args, unsigned long long), "0123456789abcdef", value,
			'p');
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), value);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), value);
	else if (c == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", value,
			'x');
	else if (c == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", value,
			'X');
	else if (c == '%')
		ft_putchar('%', value);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	va_list	args;
	int		value;

	value = 0;
	va_start(args, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			ft_printf_args(s[i + 1], args, &value);
			i++;
		}
		else
			ft_putchar(s[i], &value);
		i++;
	}
	va_end(args);
	return (value);
}
