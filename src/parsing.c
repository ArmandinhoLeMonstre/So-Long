/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:26:45 by armitite          #+#    #+#             */
/*   Updated: 2024/06/26 15:30:36 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*rectangle(int fd, int test)
{
	t_rectangle	rec;

	test = 1;
	rec.str = get_next_line(fd);
	rec.map = ft_strdup(rec.str);
	rec.i = ft_strlen_spe(rec.str);
	while (test > 0)
	{
		free(rec.str);
		rec.str = get_next_line(fd);
		if (!rec.str)
			break ;
		rec.map = ft_strjoin(rec.map, rec.str);
		test = ft_strlen_spe(rec.str);
		if (rec.i != test)
		{
			free(rec.map);
			rec.i = -1;
			break ;
		}
	}
	free(rec.str);
	if (rec.i == -1)
		return (NULL);
	return (rec.map);
}

int	checkmurs(char *map)
{
	int		base;
	int		total;
	char	**res;
	int		i;
	int		nbr;

	i = 0;
	base = ft_strlen_spe(map);
	res = ft_split(map, '\n');
	nbr = ft_strlensplit(res) + 1;
	i = ft_strncmp(res[0], '1', base);
	if (i != 0)
		return (ft_free(res), -1);
	i = ft_strncmp(res[nbr - 1], '1', base);
	if (i != 0)
		return (ft_free(res), -1);
	total = 1;
	while (total < nbr - 1)
	{
		if (res[total][i] != '1' || res[total][base - 1] != '1')
			return (ft_free(res), -1);
		total++;
	}
	return (ft_free(res), 0);
}

int	ft_parsing(int fd, t_backtrack *vars)
{
	vars->map = rectangle(fd, 1);
	if (!vars->map)
		return (0);
	vars->check = checkmurs(vars->map);
	if (vars->check == -1)
		return (0);
	vars->e = check_e(vars->map, vars->e);
	vars->p = check_p(vars->map, vars->p);
	vars->c = check_c(vars->map, vars->c);
	if (!(vars->check == 0 && vars->e == 1 && vars->p == 1 && vars->c > 0))
		return (0);
	vars = player_pos(vars->map, vars);
	vars->obj = vars->c;
	vars->exit = 1;
	vars->maps = ft_split(vars->map, '\n');
	if (ft_backtrack(vars->maps, vars->xp, vars->yp, vars) == 0)
		return (ft_free(vars->maps), 0);
	return (ft_free(vars->maps), 1);
}

int	main(int ac, char **av)
{
	int			fd;
	t_backtrack	vars;

	if (ac != 2)
	{
		ft_printf("Error : trop/pas assez d'arguments\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (ft_strbercmp(ft_strchr(av[1], '.'), "ber", 4) != 0)
	{
		ft_printf("Error : pas .ber\n");
		return (1);
	}
	else if (ft_parsing(fd, &vars) == 1)
		makegame(vars.map, vars.xp, vars.yp, vars.c);
	else
		ft_printf("Error : Invalid map\n");
	return (0);
}
