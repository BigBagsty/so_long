/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarc2 <fragarc2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:26:20 by fragarc2          #+#    #+#             */
/*   Updated: 2025/03/11 16:09:00 by fragarc2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int is_valid_move(t_data *data, int **visited, int row, int col)
{
    return (data->map.map[row][col] != '1' && !visited[row][col]);
}

void flood_fill(t_data *data, int row, int col, int **visited)
{
    if (!is_valid_move(data, visited, row, col) || visited[row][col])
        return;
    visited[row][col] = 1;
    if (data->map.map[row][col] == 'C')
        data->map.co += 1;
    flood_fill(data, row - 1, col, visited);
    flood_fill(data, row + 1, col, visited);
    flood_fill(data, row, col - 1, visited);
    flood_fill(data, row, col + 1, visited);
}

void find_player_position(t_data *data, int *p_row, int *p_col)
{
    int i = 0;
    while (data->map.map[i])
    {
        int j = 0;
        while (data->map.map[i][j])
        {
            if (data->map.map[i][j] == 'P')
            {
                *p_row = i;
                *p_col = j;
                return;
            }
            j++;
        }
        i++;
    }
    *p_row = -1;
    *p_col = -1;
}

int allocate_visited(t_data *data, int ***visited)
{
    int i = 0;
    *visited = (int **)malloc(sizeof(int *) * data->map.line_count);
    if (!*visited)
        return (0);
    while (i < data->map.line_count)
    {
        (*visited)[i] = (int *)malloc(sizeof(int) * data->map.line_len);
        if (!(*visited)[i])
        {
            while (i > 0)
                free((*visited)[--i]);
            free(*visited);
            return (0);
        }
        int j = 0;
        while (j < ((int)data->map.line_len))
            (*visited)[i][j++] = 0;
        i++;
    }
    return (1);
}

int validate_coins(t_data *data)
{
    int **visited;
    int p_row, p_col;

	if (data->map.count_p > 1)
		return (0);
    if (!allocate_visited(data, &visited))
        return (0);
    find_player_position(data, &p_row, &p_col);
    if (p_row == -1 || p_col == -1)
    {
        while (data->map.line_count--)
            free(visited[data->map.line_count]);
        free(visited);
        return (0);
    }
    data->map.co = 0;
    flood_fill(data, p_row, p_col, visited);
    while (data->map.line_count--)
        free(visited[data->map.line_count]);
    free(visited);
    return (data->map.co == data->map.count_c);
}
