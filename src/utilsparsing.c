/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsparsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:24:55 by armitite          #+#    #+#             */
/*   Updated: 2024/06/26 14:53:14 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strncmp(const char *s1, char s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2)
			return ((unsigned char) s1[i] - (unsigned char) s2);
		i++;
	}
	return (0);
}

void	*ft_calloc(int count, int size)
{
	unsigned char	*tmp;
	int				i;

	tmp = malloc(size * count);
	i = 0;
	if (!tmp)
		return (0);
	while (i < size * count)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

int	ft_strbercmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (!s1)
		return (-1);
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

int	ft_strlen_spe(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}
