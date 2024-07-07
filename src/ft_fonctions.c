/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:12:28 by armitite          #+#    #+#             */
/*   Updated: 2024/06/25 01:38:57 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int n, int h)
{
	char	c;

	if (n == -2147483648)
	{
		h += write(1, "-2147483648", 11);
		return (h);
	}
	if (n < 0)
	{
		h += write(1, "-", 1);
		h += ft_putnbr(-n, 0);
	}
	else if (n > 9)
	{
		h += ft_putnbr((n / 10), h);
		c = (n % 10) + '0';
		h += write(1, &c, 1);
	}
	else
	{
		c = n + 48;
		h += write(1, &c, 1);
	}
	return (h);
}

int	ft_putnbr_u(unsigned int n, int fd, int h)
{
	char	c;

	if (n > 9)
	{
		h += ft_putnbr_u((n / 10), fd, h);
		c = (n % 10) + '0';
		h += write(fd, &c, 1);
	}
	else
	{
		c = n + 48;
		h += write(fd, &c, 1);
	}
	return (h);
}
