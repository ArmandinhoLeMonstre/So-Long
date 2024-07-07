/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:16:09 by armitite          #+#    #+#             */
/*   Updated: 2024/06/26 15:03:32 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	p;

	i = 0;
	p = c;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == p)
			return ((char *) &s[i + 1]);
		i++;
	}
	if (s[i] == p)
		return ((char *) &s[i + 1]);
	return (0);
}

size_t	ft_strlensplit(char **s)
{
	size_t	i;

	i = 0;
	if (s[i] == 0)
		return (0);
	while (s[i][0])
	{
		if (s[i + 1] == 0)
			return (i);
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (free((void *) s1), NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = 0;
	free((void *) s1);
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	dst = (char *) malloc(ft_strlen(s1) + 1);
	if (!dst)
		return (0);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
