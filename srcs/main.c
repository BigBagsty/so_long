/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:06:56 by marvin            #+#    #+#             */
/*   Updated: 2024/12/28 16:06:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		create_map(argv[1], &data);
		init_map(&data);
		check_map(&data);
		init_player(&data);
		init_window(&data);
		init_images(&data);
		render(&data);
		loop_images(data);
		destroy_images(data);
		free(data.mlx);
		if (data.map.map)
			ft_free(data.map.map);
	}
}