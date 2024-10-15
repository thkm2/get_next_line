/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:53:37 by kgiraud           #+#    #+#             */
/*   Updated: 2024/10/15 12:11:26 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		bread;
	char	*new;
	char	*tmp;
	int		i;

	new = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i = 0;
	while (i < BUFFER_SIZE)
	{
		bread = read(fd, buffer, 1);
		if (bread == -1)
		{
			free(new);
			return (NULL);
		}
		else if (bread == 0)
			break ;
		new[i++] = buffer[0];
		if (buffer[0] == '\n')
			break ;
	}
	tmp = realloc(new, i + 1);
	if (!tmp || i == 0)
	{
		free(new);
		free(tmp);
		return (NULL);
	}
	new[i] = '\0';
	return (new);
}

#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}