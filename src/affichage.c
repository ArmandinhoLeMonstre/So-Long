/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:19:25 by armitite          #+#    #+#             */
/*   Updated: 2024/06/26 15:20:49 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <mlx.h>

void	ft_init(t_mlx *game)
{
	game->sol = mlx_xpm_file_to_image(game->mlx, "xpm/Sol.xpm",
			&game->img_width, &game->img_height);
	game->mur = mlx_xpm_file_to_image(game->mlx, "xpm/Mur.xpm",
			&game->img_width, &game->img_height);
	game->obj = mlx_xpm_file_to_image(game->mlx, "xpm/Potion.xpm",
			&game->img_width, &game->img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "xpm/Lave.xpm",
			&game->img_width, &game->img_height);
	game->playerw = mlx_xpm_file_to_image(game->mlx, "xpm/Devant.xpm",
			&game->img_width, &game->img_height);
	game->playera = mlx_xpm_file_to_image(game->mlx, "xpm/GAUCHE.xpm",
			&game->img_width, &game->img_height);
	game->playerd = mlx_xpm_file_to_image(game->mlx, "xpm/DROITE.xpm",
			&game->img_width, &game->img_height);
	game->players = mlx_xpm_file_to_image(game->mlx, "xpm/De-dos.xpm",
			&game->img_width, &game->img_height);
}

int	ft_gety(char *map)
{
	int		nbr;
	char	**res;

	res = ft_split(map, '\n');
	nbr = ft_strlensplit(res) + 1;
	ft_free(res);
	return (nbr);
}

void	ft_base2(t_mlx game, char *map)
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
			if (map[z] == '1')
				mlx_put_image_to_window(game.mlx, game.mlx_win,
					game.mur, k * 64, i * 64);
			else if (map[z] == 'C')
				mlx_put_image_to_window(game.mlx, game.mlx_win,
					game.obj, k * 64, i * 64);
			k++;
			z++;
		}
		i++;
		z++;
		k = 0;
	}
}

void	ft_base(t_mlx game, char *map)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < game.y)
	{
		while (k < game.x)
		{
			mlx_put_image_to_window(game.mlx, game.mlx_win,
				game.sol, k * 64, i * 64);
			k++;
		}
		i++;
		k = 0;
	}
	ft_base2(game, map);
}

int	makegame(char *map, int xp, int yp, int c)
{
	t_mlx	game;

	game.step = 1;
	game.y = ft_gety(map);
	game.x = ft_strlen_spe(map);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.x * 64,
			game.y * 64, "Pass the lava");
	ft_init(&game);
	game.c = c;
	ft_base(game, map);
	game.xp = xp;
	game.yp = yp;
	game.map = map;
	mlx_put_image_to_window(game.mlx, game.mlx_win,
		game.playerw, xp * 64, yp * 64);
	mlx_hook(game.mlx_win, 17, 0, ft_exit, &game);
	mlx_key_hook(game.mlx_win, key, &game);
	mlx_loop(game.mlx);
	return (0);
}
