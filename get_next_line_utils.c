/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:53:42 by kgiraud           #+#    #+#             */
/*   Updated: 2024/10/19 16:00:49 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_find_new_line(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	int		j;
	char	*rs;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	j = 0;
	rs = (char *)malloc(sizeof(char) * (len + 1));
	if (!rs)
		return (NULL);
	while (s1[++i])
		rs[i] = s1[i];
	while (s2[j])
	{
		rs[i + j] = s2[j];
		j++;
	}
	rs[i + j] = '\0';
	free(s1);
	s1 = NULL;
	return (rs);
}

char	*ft_strndup(char *s, int n)
{
	int		len;
	char	*rs;

	len = ft_strlen(s);
	if (n < len)
		len = n;
	rs = (char *)malloc(sizeof(char) * (len + 1));
	if (!rs)
		return (NULL);
	rs[len] = '\0';
	while (len-- > 0)
		rs[len] = s[len];
	return (rs);
}

char	*ft_get_line(char *s)
{
	int		len;
	char	*tmp;
	char	*line;

	tmp = ft_find_new_line(s);
	if (tmp)
		len = tmp - s + 1;
	else
		len = ft_strlen(s);
	line = ft_strndup(s, len);
	if (!len)
		return (NULL);
	return (line);
}

char	*ft_get_rest(char *s)
{
	char	*tmp;
	char	*rest;

	tmp = ft_find_new_line(s);
	if (!tmp)
	{
		free(s);
		return (NULL);
	}
	tmp += 1;
	rest = ft_strndup(tmp, ft_strlen(tmp));
	if (!rest)
		return (NULL);
	free(s);
	return (rest);
}