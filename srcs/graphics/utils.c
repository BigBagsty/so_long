/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/08 19:28:59 by marvin            #+#    #+#             */
/*   Updated: 2025/01/08 19:28:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	init_window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"Treasure");
	if (data->win == NULL)
	{
		free(data->win);
		return (-1);
	}
	return (0);
}

void	init_images(t_data *data)
{
	data->img.ground = mlx_xpm_file_to_image(data->mlx, GROUND,
			&data->img.width, &data->img.height);
	data->img.exit_l = mlx_xpm_file_to_image(data->mlx, LOCKED,
			&data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, PLAYER,
			&data->img.width, &data->img.height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, WALL, &data->img.width,
			&data->img.height);
	data->img.coin = mlx_xpm_file_to_image(data->mlx, COIN, &data->img.width,
			&data->img.height);
}

void	loop_images(t_data data)
{
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, ClientMessage, LeaveWindowMask, &handle_btnrealease,
		&data);
	mlx_loop(data.mlx);
}

void	destroy_images(t_data data)
{
	mlx_destroy_image(data.mlx, data.img.wall);
	mlx_destroy_image(data.mlx, data.img.ground);
	mlx_destroy_image(data.mlx, data.img.player);
	mlx_destroy_image(data.mlx, data.img.exit_l);
	mlx_destroy_image(data.mlx, data.img.coin);
	mlx_destroy_display(data.mlx);
}
