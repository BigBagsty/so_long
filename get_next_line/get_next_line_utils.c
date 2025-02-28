/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:02:04 by marvin            #+#    #+#             */
/*   Updated: 2025/02/28 13:02:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/get_next_line.h"

size_t	ft_strln(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*f_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (*s != (char)c)
		return (NULL);
	return (s);
}

char	*f_strdup(char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc((ft_strln(s1) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*f_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	if (s1 == NULL)
		return (f_strdup(s2));
	res = (char *)malloc(sizeof(char) * (ft_strln(s1) + ft_strln(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	free(s1);
	return (res);
}