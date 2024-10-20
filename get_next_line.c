/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:21:16 by kgiraud           #+#    #+#             */
/*   Updated: 2024/10/20 19:09:44 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *rest, char *buffer)
{
	int		len;
	char	*new;

	len = ft_strlen(rest) + ft_strlen(buffer);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
	{
		free(rest);
		return (NULL);
	}
	new = ft_strcat_in_memory(new, rest, buffer, len);
	free(rest);
	return (new);
}

char	*ft_read_until_nl(int fd, char *buffer, char *rest)
{
	int	bytes_read;

	bytes_read = 1;
	while (!ft_find_nl(rest) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(rest);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		rest = ft_strjoin(rest, buffer);
	}
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rest = ft_read_until_nl(fd, buffer, rest);
	line = ft_find_line(rest);
	rest = ft_find_rest(rest);
	return (line);
}

/* #include <stdio.h>
#include <fcntl.h>
int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
} */