/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:22:21 by armitite          #+#    #+#             */
/*   Updated: 2024/06/25 01:38:57 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_count(const char *format, va_list(args), int i)
{
	int	x;

	x = 0;
	if (format[i] == 's')
		x = ft_putstr(va_arg(args, char *));
	if (format[i] == 'c')
		x = ft_putchar(va_arg(args, int));
	if (format[i] == 'd' || format[i] == 'i')
		x = ft_putnbr(va_arg(args, int), 0);
	if (format[i] == 'u')
		x = ft_putnbr_u(va_arg(args, unsigned int), 1, 0);
	if (format[i] == 'p')
		x = ft_putstr("0x")
			+ ft_putnbr_base(va_arg(args, unsigned long int),
				"0123456789abcdef");
	if (format[i] == 'x')
		x = ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	if (format[i] == 'X')
		x = ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (format[i] == '%')
		x = ft_putchar('%');
	return (x);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		h;
	int		x;
	va_list	args;

	va_start(args, format);
	i = 0;
	x = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			h = ft_count(format, args, i);
			x += h;
		}
		else
			x += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (x);
}
