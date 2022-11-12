/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:06:57 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/12 10:47:21 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

void ft_drawn_line (char **map_data, t_map *map, int line);
void ft_drawn_map (char **map_data, t_map *map, int line);

void	hook(void *param)
{
	t_map *map;
	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_Q))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
	{
		// if (map->map_data[map->player_x][map->player_y + 1] != 1)
		if (map->player_y > 1)
		{
		map->player->instances[0].y -= MOVE;
		map->steps ++;
		map->player_y = map->player_y - 1;
		ft_printf("The number of stepst is:%i\n", map->steps);
		}
		// if (map->player_y == 6)
		// 	ft_printf("x y is%c\n", map->map_data[1][6]);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
	{
		if (map->player_y < 5)
		{
		map->player->instances[0].y += MOVE;
		map->steps ++;
		map->player_y = map->player_y + 1;
		ft_printf("The number of stepst is:%i\n", map->steps);
		}
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
	{
		if (map->player_x > 1)
		{
		map->player->instances[0].x -= MOVE;
		map->steps ++;
		map->player_x = map->player_x - 1;
		ft_printf("The number of stepst is:%i\n", map->steps);
		}
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
	{
		if (map->map_data[map->player_y][map->player_x + 1] != '1')
		// if (map->player_x < 13)
		{
		map->player->instances[0].x += MOVE;
		map->steps ++;
		map->player_x = map->player_x + 1;
		ft_printf("The number of stepst is:%i\n", map->steps);
		}
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_P))
	{
		ft_printf("\nZ data is:%i\n", map->player->instances->z);
		ft_printf("player x is:%i, player y is:%i\n", map->player_x, map->player_y);
	}
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	int		i;

	i = 1;
	map = malloc (sizeof(t_map *));
	ft_map_init(map);;
	// ft_read_line(argv, ft_line_size(argv));
	map->map_data = ft_get_map(argv);
	ft_get_map_2(argv);
	if (map->map_data == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	map->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	ft_elem_init(map);
	while (i < 6)
	{
	ft_drawn_line(map->map_data, map, i);
	i++;
	}
	mlx_loop_hook(map->mlx, &hook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	return (0);
}

void ft_drawn_line (char **map_data, t_map *map, int line)
{
	int j;
	char	**m_data;
	t_map	*tmp_map;

	tmp_map = map;
	m_data = map_data;
	j = 1;

	while (m_data[line][j - 1] != '\0')
	{
		ft_printf("y:%i x:%i\n",line, j);
		// ft_printf("%c", m_data[line][j - 1]);
		if (m_data[line][j - 1] == '0')
			mlx_image_to_window(map->mlx, map->space, ((j -1)  * 50), ((line -1) * 50));
		else if (m_data[line][j - 1] == '1')
			mlx_image_to_window(map->mlx, map->wall, ((j - 1) * 50), ((line -1) * 50));
		else if (m_data[line][j - 1] == 'C')
			mlx_image_to_window(map->mlx, map->collectable, ((j - 1) * 50), ((line -1) * 50));
		else if (m_data[line][j - 1] == 'P')
		{
			mlx_image_to_window(map->mlx, map->space, ((j - 1) * 50), ((line -1) * 50));
			mlx_image_to_window(map->mlx, map->player, ((j - 1) * 50), ((line -1) * 50));
			map->player_x = j;
			map->player_y = line;
		}
		else if (m_data[line][j - 1] == 'E')
			mlx_image_to_window(map->mlx, map->exit, ((j - 1) * 50), ((line -1) * 50));
		j++;
	}
}

void ft_drawn_map (char **map_data, t_map *map, int line)
{

}