/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:57:58 by armitite          #+#    #+#             */
/*   Updated: 2024/06/25 02:43:23 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_backtrack	*player_pos(char *line, t_backtrack *vars)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			return (vars);
		else if (line[i] == '\n')
		{
			vars->xp = 0;
			vars->yp += 1;
			i++;
		}
		else
		{
			i++;
			vars->xp += 1;
		}
	}
	return (vars);
}

int	ft_backtrack(char **maps, int x, int y, t_backtrack *vars)
{
	if (maps[y][x] == '1' || maps[y][x] == 'k')
		return (0);
	if (maps[y][x] == 'C' || maps[y][x] == 'E' || maps[y][x] == '0'
		|| maps[y][x] == 'P')
	{
		if (maps[y][x] == 'C')
			vars->obj--;
		if (maps[y][x] == 'E')
			vars->e--;
		maps[y][x] = 'k';
	}
	ft_backtrack(maps, (x + 1), y, vars);
	ft_backtrack(maps, (x - 1), y, vars);
	ft_backtrack(maps, x, (y + 1), vars);
	ft_backtrack(maps, x, (y - 1), vars);
	if (vars->obj == 0 && vars->e == 0)
		return (1);
	return (0);
}
