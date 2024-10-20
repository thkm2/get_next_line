/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:53:42 by kgiraud           #+#    #+#             */
/*   Updated: 2024/10/20 14:35:21 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_find_new_line(char *s)
{
	int	i;

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

	if (!s || !*s)
		return (NULL);
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

	if (!s)
		return (NULL);
	tmp = ft_find_new_line(s);
	if (!tmp)
	{
		free(s);
		return (NULL);
	}
	tmp += 1;
	rest = ft_strndup(tmp, ft_strlen(tmp));
	free(s);
	if (!rest)
		return (NULL);
	return (rest);
}
