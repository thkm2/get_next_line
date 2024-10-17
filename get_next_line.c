/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:53:37 by kgiraud           #+#    #+#             */
/*   Updated: 2024/10/17 20:35:56 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_buffer(int fd, char *buffer)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 1)
		return (NULL);
	buffer[bytes_read] = '\0';
	return (buffer);
}

char	*find_new_line(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_find_line(int fd, char *buffer, char **rest)
{
	char	*content_read;
	char	*nl_index;
	char	*tmp;
	char	*line;

	line = NULL;
	if (*rest)
		content_read = *rest;
	else
		content_read = read_until_buffer(fd, buffer);
	nl_index = find_new_line(content_read);
	while (!nl_index)
	{
		tmp = read_until_buffer(fd, buffer);
		if (!tmp)
			break;
		content_read = ft_strjoin(content_read, tmp);
		nl_index = find_new_line(content_read);
	}
	if (nl_index)
		line = ft_strndup(content_read, nl_index - content_read + 1);
	else if (*content_read)
		line = ft_strdup(content_read);
	free(content_read);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_find_line(fd, buffer, &rest);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}