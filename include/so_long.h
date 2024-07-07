/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:15:23 by armitite          #+#    #+#             */
/*   Updated: 2024/06/26 14:57:48 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_rectangle
{
	int		i;
	char	*str;
	char	*map;
}				t_rectangle;

typedef struct s_backtrack
{
	int		check;
	int		e;
	int		c;
	char	**maps;
	int		xp;
	int		yp;
	int		p;
	int		obj;
	int		exit;
	char	*map;
}				t_backtrack;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*sol;
	void	*mur;
	void	*obj;
	void	*exit;
	void	*playerw;
	void	*playera;
	void	*players;
	void	*playerd;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		y;
	int		x;
	int		xp;
	int		yp;
	char	*map;
	int		base;
	int		c;
	char	**res;
	int		step;
}				t_mlx;

char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
size_t		ft_strlensplit(char **s);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strdup(const char *s1);
void		ft_bzero(void *s, size_t n);
char		*ft_oneline(char *stash, char *res, int x);
char		*get_next_line(int fd);
char		*ft_oneline(char *stash, char *res, int x);
char		*ft_fin(char *stash, int fd);
int			ft_parsing(int fd, t_backtrack *vars);
char		*rectangle(int fd, int test);
int			ft_strlen_spe(char *str);
int			ft_strncmp(const char *s1, char s2, int n);
char		**ft_split(char const *s, char c);
void		*ft_calloc(int count, int size);
int			check_e(char *map, int e);
int			check_p(char *map, int p);
int			check_c(char *map, int c);
int			ft_backtrack(char **maps, int x, int y, t_backtrack *vars);
t_backtrack	*player_pos(char *line, t_backtrack *vars);
int			makegame(char *map, int xp, int yp, int c);
int			ft_gety(char *map);
void		ft_base(t_mlx game, char *map);
int			key(int keycode, t_mlx *game);
int			ft_checkun(t_mlx game, int p);
int			ft_printf(const char *format, ...);
int			ft_putstr(char *str);
int			ft_putchar(char c);
int			ft_putnbr(int n, int h);
int			ft_putnbr_u(unsigned int n, int fd, int h);
int			ft_putnbr_base(unsigned long i, char *base);
int			ft_strbercmp(const char *s1, const char *s2, int n);
void		*ft_free(char **strs);
void		ft_putexit(t_mlx game);
int			ft_checkexit(t_mlx *game);
int			ft_checkobj(t_mlx *game);
int			ft_checkun(t_mlx game, int p);
int			ft_exit(t_mlx *game);
#endif