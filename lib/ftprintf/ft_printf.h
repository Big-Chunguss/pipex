/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:16:17 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/19 16:16:19 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_printf_args(char c, va_list args, int *value);
void	ft_putchar(char c, int *value);
void	ft_putstr(char *str, int *value);
void	ft_putnbr(int nb, int *value);
void	ft_putnbr_unsigned(unsigned int nb, int *value);
void	ft_putnbr_base(unsigned long long nbr, char *base, int *value,
			char type);
void	ft_printf_p(unsigned long long nbr, char *base, int *value,
			char type);
#endif
