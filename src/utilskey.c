/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilskey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:54:33 by armitite          #+#    #+#             */
/*   Updated: 2024/07/03 15:28:08 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_putexit(t_mlx game)
{
	int	i;
	int	k;
	int	z;

	i = 0;
	k = 0;
	z = 0;
	while (i < game.y)
	{
		while (k < game.x)
		{
			if (game.map[z] == 'E')
				mlx_put_image_to_window(game.mlx, game.mlx_win,
					game.exit, k * 64, i * 64);
			k++;
			z++;
		}
		i++;
		z++;
		k = 0;
	}
}

int	ft_checkexit(t_mlx *game)
{
	char	**res;

	res = ft_split(game->map, '\n');
	if (res[game->yp][game->xp] == 'E')
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		ft_free(res);
		exit(0);
	}
	ft_free(res);
	return (0);
}

int	ft_checkobj(t_mlx *game)
{
	char	**res;
	int		i;

	i = (game->yp * (game->x)) + game->xp + game->yp;
	res = ft_split(game->map, '\n');
	if (res[game->yp][game->xp] == 'C')
	{
		game->c--;
		game->map[i] = '0';
		return (ft_free(res), -1);
	}
	ft_free(res);
	return (0);
}

int	ft_checkun(t_mlx game, int p)
{
	char	**res;

	res = ft_split(game.map, '\n');
	if (p == 0)
	{
		if (res[game.yp][game.xp - 1] == '1')
			return (ft_free(res), 1);
	}
	if (p == 1)
	{
		if (res[game.yp][game.xp + 1] == '1')
			return (ft_free(res), 1);
	}
	if (p == 2)
	{
		if (res[game.yp + 1][game.xp] == '1')
			return (ft_free(res), 1);
	}
	if (p == 3)
	{
		if (res[game.yp - 1][game.xp] == '1')
			return (ft_free(res), 1);
	}
	ft_free(res);
	return (0);
}

int	ft_exit(t_mlx *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}
