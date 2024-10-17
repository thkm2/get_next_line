/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:53:42 by kgiraud           #+#    #+#             */
/*   Updated: 2024/10/17 19:21:27 by kgiraud          ###   ########.fr       */
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

char	*ft_strdup(char *s)
{
	int		len;
	char	*rs;

	len = ft_strlen(s);
	rs = (char *)malloc(sizeof(char) * (len + 1));
	if (!rs)
		return (NULL);
	while (len >= 0)
	{
		rs[len] = s[len];
		len--;
	}
	free(s);
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
	free(s);
	return (rs);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	int		j;
	char	*rs;

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
	return (rs);
}


