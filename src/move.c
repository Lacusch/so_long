/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:15:06 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/19 13:29:04 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_up(t_map *map)
{
	if (map->map_data[map->player_y - 1][map->player_x] != '1')
	{
		map->player->instances[0].y -= MOVE;
		map->steps++;
		map->player_y = map->player_y - 1;
		ft_printf("The number of stepst is:%i\n", map->steps);
	}
}

void	ft_move_down(t_map *map)
{
	if (map->map_data[map->player_y + 1][map->player_x] != '1')
	{
		map->player->instances[0].y += MOVE;
		map->steps++;
		map->player_y = map->player_y + 1;
		ft_printf("The number of stepst is:%i\n", map->steps);
	}
}

void	ft_move_left(t_map *map)
{
	if (map->map_data[map->player_y][map->player_x - 1] != '1')
	{
		map->player->instances[0].x -= MOVE;
		map->steps++;
		map->player_x = map->player_x - 1;
		ft_printf("The number of stepst is:%i\n", map->steps);
	}
}

void	ft_move_right(t_map *map)
{
	if (map->map_data[map->player_y][map->player_x + 1] != '1')
	{
		map->player->instances[0].x += MOVE;
		map->steps++;
		map->player_x = map->player_x + 1;
		ft_printf("The number of stepst is:%i\n", map->steps);
	}
}
