/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarc2 <fragarc2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:09:29 by fragarc2          #+#    #+#             */
/*   Updated: 2025/03/11 17:29:06 by fragarc2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"


int ft_check(char* av)
{
	if (!ft_strnstr(av, ".ber\0", ft_strlen(av)))
			return (1);
		int fd = open(av, O_RDONLY);
		if (fd < 0)
			return (1);
		else
			close (fd);
	return (0);
}
