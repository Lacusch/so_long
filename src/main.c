/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <coder@slaszlo-@student.42heib    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:06:57 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/18 15:52:10 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

bool ft_parce_error(int argc, char**argv);

void hook(void *param)
{
	t_map *map;
	map = param;
	ft_get_collectable(map);
	if (map->map_data[map->player_y][map->player_x] == 'E' && map->coints == 0)
	{
		mlx_close_window(map->mlx);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_Q))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
	{

		if (map->map_data[map->player_y - 1][map->player_x] != '1')
		{
			map->player->instances[0].y -= MOVE;
			map->steps++;
			map->player_y = map->player_y - 1;
			ft_printf("The number of stepst is:%i\n", map->steps);
		}
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
	{
		if (map->map_data[map->player_y + 1][map->player_x] != '1')
		{
			map->player->instances[0].y += MOVE;
			map->steps++;
			map->player_y = map->player_y + 1;
			ft_printf("The number of stepst is:%i\n", map->steps);
		}
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
	{
		if (map->map_data[map->player_y][map->player_x - 1] != '1')
			if (map->player_x != 1)
			{
				map->player->instances[0].x -= MOVE;
				map->steps++;
				map->player_x = map->player_x - 1;
				ft_printf("The number of stepst is:%i\n", map->steps);
			}
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
	{
		if (map->map_data[map->player_y][map->player_x + 1] != '1')
		{
			map->player->instances[0].x += MOVE;
			map->steps++;
			map->player_x = map->player_x + 1;
			ft_printf("The number of stepst is:%i\n", map->steps);
		}
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_P))
	{
		// ft_printf("\nZ data is:%i\n", map->player->instances->z);
		// ft_printf("player x is:%i, player y is:%i\n", map->player_x, map->player_y);
		// if (map->player->instances[0].enabled == false)
		// 	map->player->instances[0].enabled = true;
		// else
		// 	map->player->instances[0].enabled = false;
		ft_printf("number of collectables is %i\n", map->coints);
		// ft_printf("player x is:%i y is%i\n", map->player_x, map->player_y);
		if (map->map_data[map->player_y][map->player_x] == 'E' && map->coints == 0)
		{
			ft_printf("end\n");
			mlx_terminate(map->mlx);
		}
	}
}

int main(int argc, char *argv[])
{
	t_map map;
	int i;
	char *big_str;

	i = 0;
	ft_map_init(&map);
	if (ft_parce_error(argc, argv) == true)
		return (1);
	big_str = ft_read_line(argv);
	if (big_str == NULL || ft_check_elem(big_str) == false)
	{
		free(big_str);
		return (1);
	}
	ft_map_dimentions(&map, big_str);
	map.map_data = ft_split(big_str, '\n');
	if (map.map_data == NULL)
	{
		ft_free_char_array(map.map_data);
		ft_printf("Error\n");
		return (1);
	}
	if (ft_check_map(&map) == true)
	{
		ft_free_char_array(map.map_data);
		free(big_str);
		return (1);
	}
	ft_player_position(&map);
	if ((flood_fill(ft_split(big_str, '\n'),&map, map.player_x, map.player_y) == 1))
	{
		ft_free_char_array(map.map_data);
		free(big_str);
		return (1);
	}
	free(big_str);
	map.mlx = mlx_init(map.width * 50, map.height * 50, "MLX42", true);
	ft_elem_init(&map);
	ft_drawn_map(&map);
	map.coints = map.collectable->count;
	mlx_loop_hook(map.mlx, &hook, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	ft_free_char_array(map.map_data);
	return (0);
}


bool ft_parce_error(int argc, char**argv)
{
	if (argc != 2)
	{
		if (argc > 2)
			ft_printf("Error\nTo many arguments");
		else
			ft_printf("Error\nNot enough arguments");
		return (1);
	}
	if (ft_check_extention(argv[1], ".ber") == false)
		return (1);
	return (0);
}