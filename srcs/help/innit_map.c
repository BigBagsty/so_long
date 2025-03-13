/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/15 16:38:53 by marvin            #+#    #+#             */
/*   Updated: 2025/01/15 16:38:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	init_map(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->i = 0;
	data->j = 0;
	data->map.count_p = 0;
	data->map.count_e = 0;
	data->map.count_c = 0;
	data->map.collected = 0;
	data->map.can_exit = 0;
	data->map.exit_r = 0;
	data->steps_count = 0;
	data->map.fd = -1;
	data->img.height = IMG_SIZE;
	data->img.width = IMG_SIZE;
}
