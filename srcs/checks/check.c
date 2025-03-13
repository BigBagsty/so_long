/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarc2 <fragarc2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:09:29 by fragarc2          #+#    #+#             */
/*   Updated: 2025/03/13 17:59:22 by fragarc2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_check(char *av)
{
	int	fd;
	int bytes;
	char *a[2];
	fd = open(av, O_RDONLY);
	bytes = read(fd, a, 1);
	if (fd < 0 || bytes == 0)
	{
		ft_putstr_fd("Error\n Invalid file.\n", 1);
		return (1);
	}
	else
		close(fd);
	return (0);
}
