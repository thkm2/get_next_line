/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:53:37 by kgiraud           #+#    #+#             */
/*   Updated: 2024/10/19 16:19:53 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_until_newline(int fd, char *buffer, char *rest)
{
	int	bytes_read;

	bytes_read = 1;
	while (!ft_find_new_line(rest) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return(NULL);
		}
		rest = ft_strjoin(rest, buffer);
	}
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rest = ft_read_until_newline(fd, buffer, rest);
	line = ft_get_line(rest);
	rest = ft_get_rest(rest);
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