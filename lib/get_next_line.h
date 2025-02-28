/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:02:09 by marvin            #+#    #+#             */
/*   Updated: 2025/02/28 13:02:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*f_strchr(char *s, int c);
char	*f_strjoin(char *s1, char *s2);
char	*f_strdup(char *s1);
char	*get_next_line(int fd);
size_t	ft_strln(const char *str);

#endif