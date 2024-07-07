/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkepc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:37:10 by armitite          #+#    #+#             */
/*   Updated: 2024/06/25 16:01:15 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_e(char *map, int e)
{
	int	i;

	i = 0;
	e = 0;
	while (map[i])
	{
		if (map[i] == 'E')
			e++;
		i++;
	}
	if (e == 1)
		return (1);
	else
		return (0);
}

int	check_p(char *map, int p)
{
	int	i;

	i = 0;
	p = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			p++;
		i++;
	}
	if (p == 1)
		return (1);
	else
		return (0);
}

int	check_c(char *map, int c)
{
	int	i;

	i = 0;
	c = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			c++;
		i++;
	}
	if (c > 0)
		return (c);
	else
		return (0);
}
