/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:29:38 by armitite          #+#    #+#             */
/*   Updated: 2024/06/26 15:17:20 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../include/so_long.h"

void	movex(t_mlx *game, int keycode)
{
	if (keycode == 0 && ft_checkun(*game, 0) == 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->sol, game->xp * 64, game->yp * 64);
		game->xp--;
		if (ft_checkobj(game) == -1)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->sol, game->xp * 64, game->yp * 64);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->playera, game->xp * 64, game->yp * 64);
		ft_printf("%d\n", game->step++);
	}
	if (keycode == 2 && ft_checkun(*game, 1) == 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->sol, game->xp * 64, game->yp * 64);
		game->xp++;
		if (ft_checkobj(game) == -1)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->sol, game->xp * 64, game->yp * 64);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->playerd, game->xp * 64, game->yp * 64);
		ft_printf("%d\n", game->step++);
	}
}

void	movey(t_mlx *game, int keycode)
{
	if (keycode == 1 && ft_checkun(*game, 2) == 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->sol, game->xp * 64, game->yp * 64);
		game->yp++;
		if (ft_checkobj(game) == -1)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->sol, game->xp * 64, game->yp * 64);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->playerw, game->xp * 64, game->yp * 64);
		ft_printf("%d\n", game->step++);
	}
	if (keycode == 13 && ft_checkun(*game, 3) == 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->sol, game->xp * 64, game->yp * 64);
		game->yp--;
		if (ft_checkobj(game) == -1)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->sol, game->xp * 64, game->yp * 64);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->players, game->xp * 64, game->yp * 64);
		ft_printf("%d\n", game->step++);
	}
}

int	key(int keycode, t_mlx *game)
{
	if (keycode == 0 || keycode == 2)
		movex(game, keycode);
	if (keycode == 1 || keycode == 13)
		movey(game, keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(0);
	}
	if (game->c == 0)
	{
		ft_putexit(*game);
		ft_checkexit(game);
	}
	return (0);
}
