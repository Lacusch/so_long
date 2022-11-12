/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:06:57 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/12 13:12:43 by slaszlo-         ###   ########.fr       */
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
		if (map->player_y != 1)
		{
		map->player->instances[0].y -= MOVE;
		map->steps ++;
		map->player_y = map->player_y - 1;
		ft_printf("The number of stepst is:%i\n", map->steps);
		}
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
	{
		if (map->player_y != map->height - 2)
		{
		map->player->instances[0].y += MOVE;
		map->steps ++;
		map->player_y = map->player_y + 1;
		ft_printf("The number of stepst is:%i\n", map->steps);
		}
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
	{
		if (map->player_x != 1)
		{
		map->player->instances[0].x -= MOVE;
		map->steps ++;
		map->player_x = map->player_x - 1;
		ft_printf("The number of stepst is:%i\n", map->steps);
		}
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
	{
		if (map->player_x < map->width -2)
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
	char	*big_str;

	i = 0;
	map = malloc (sizeof(t_map *));
	big_str = ft_read_line(argv);
	ft_map_init(map, big_str);
	map->map_data = ft_split(big_str, '\n');
	if (map->map_data == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	map->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	ft_elem_init(map);
	while (i < 5)
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
	j = 0;
	
	ft_printf("%s\n", m_data[line]);
	while (m_data[line][j] != '\0')
	{
		// ft_printf("y:%i x:%i\n",line, j);
		// ft_printf("%c", m_data[line][j]);
		if (m_data[line][j] == '0')
			mlx_image_to_window(map->mlx, map->space, ((j)  * 50), ((line) * 50));
		else if (m_data[line][j] == '1')
			mlx_image_to_window(map->mlx, map->wall, ((j) * 50), ((line) * 50));
		else if (m_data[line][j] == 'C')
			mlx_image_to_window(map->mlx, map->collectable, ((j) * 50), ((line) * 50));
		else if (m_data[line][j] == 'P')
		{
			mlx_image_to_window(map->mlx, map->space, ((j) * 50), ((line) * 50));
			mlx_image_to_window(map->mlx, map->player, ((j) * 50), ((line) * 50));
			map->player_x = j;
			map->player_y = line;
		}
		else if (m_data[line][j] == 'E')
			mlx_image_to_window(map->mlx, map->exit, ((j) * 50), ((line) * 50));
		j++;
	}
}


void ft_drawn_map (char **map_data, t_map *map, int line)
{

}