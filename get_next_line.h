/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:52:25 by kgiraud           #+#    #+#             */
/*   Updated: 2024/10/19 15:22:26 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

int		ft_strlen(char *s);
char	*ft_find_new_line(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *s);
char	*ft_get_rest(char *s);

#endif