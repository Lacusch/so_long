/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:56:41 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/19 13:28:47 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	hook(void *param)
{
	t_map	*map;

	map = param;
	ft_get_collectable(map);
	if ((map->map_data[map->player_y][map->player_x] == 'E' && map->coints == 0)
		|| mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(map->mlx, MLX_KEY_Q))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
		ft_move_up(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		ft_move_down(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		ft_move_left(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		ft_move_right(map);
}
