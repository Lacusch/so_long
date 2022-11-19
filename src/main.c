/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:06:57 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/19 12:55:46 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"
#include <stdlib.h>

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

int	main(int argc, char *argv[])
{
	t_map	map;
	int		i;

	i = 0;
	ft_map_init(&map);
	if (ft_parce_error(argc, argv) == true || ft_is_empty(argv) == true)
		return (1);
	if (ft_map_correct(argv, &map) == true)
		return (1);
	map.mlx = mlx_init(map.width * 50, map.height * 50, "MLX42", true);
	ft_elem_init(&map);
	ft_drawn_map(&map);
	map.coints = map.collectable->count;
	mlx_loop_hook(map.mlx, &hook, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	ft_big_fre(map.map_data, NULL, 0);
	return (0);
}

bool	ft_map_correct(char **argv, t_map *map)
{
	char	*big_str;

	big_str = ft_read_line(argv);
	if (big_str == NULL || ft_check_elem(big_str) == false)
		return (ft_big_fre(NULL, big_str, 1));
	ft_map_dimentions(map, big_str);
	map->map_data = ft_split(big_str, '\n');
	if (map->map_data == NULL)
	{
		ft_printf("Error\n");
		return (ft_big_fre(NULL, big_str, 1));
	}
	if (ft_check_map(map) == true)
		return (ft_big_fre(map->map_data, big_str, 1));
	ft_player_position(map);
	if ((flood_fill(ft_split(big_str, '\n'),
				map, map->player_x, map->player_y) == 1))
	{
		return (ft_big_fre(map->map_data, big_str, 1));
	}
	free(big_str);
	return (false);
}

bool	ft_parce_error(int argc, char**argv)
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

int	ft_big_fre(char **str_str, char *str, int ret)
{
	if (str_str != NULL)
	{
		ft_free_char_array(str_str);
		free(str_str);
	}
	if (str != NULL)
		free(str);
	return (ret);
}

bool	ft_is_empty(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nEmpy map");
		return (1);
	}
	close(fd);
	return (0);
}
