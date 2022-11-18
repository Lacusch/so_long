/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <coder@slaszlo-@student.42heib    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:06:57 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/18 13:32:17 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

void ft_drawn_line(t_map *map, int line);
void ft_drawn_map(t_map *map);
void ft_drawn_player(t_map *map, int line);
void ft_get_collectable(t_map *map);
void ft_free_char_array(char **str_str);

void hook(void *param)
{
	t_map *map;
	map = param;
	ft_get_collectable(map);
	if (map->map_data[map->player_y][map->player_x] == 'E' && map->coints == 0)
		mlx_close_window(map->mlx);
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
		if (map->player->instances[0].enabled == false)
			map->player->instances[0].enabled = true;
		else
			map->player->instances[0].enabled = false;
		;
		ft_printf("number of collectables is %i\n", map->coints);
		ft_printf("player x is:%i y is%i\n", map->player_x, map->player_y);
		if (map->map_data[map->player_y][map->player_x] == 'E' && map->coints == 0)
		{
			ft_printf("end\n");
			ft_free_char_array(map->map_data);
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
	big_str = ft_read_line(argv);
	if (big_str == NULL)
	{
		// free(map);
		free(big_str);
		return (1);
	}
	if (ft_check_elem(big_str) == false)
	{
		// free(map);
		free(big_str);
		return (1);
	}
	ft_map_dimentions(&map, big_str);
	map.map_data = ft_split(big_str, '\n');
	// free(big_str);
	if (ft_check_map(&map) == true)
	{
		free(&map);
		return (1);
	}
	ft_player_position(&map);
	if ((flood_fill(ft_split(big_str, '\n'),&map, map.player_x, map.player_y) == 1))
	{
		free(big_str);
		return (1);
	}
	free(big_str);
	if (map.map_data == NULL)
	{
		ft_free_char_array(map.map_data);
		ft_printf("Error\n");
		return (1);
	}
	map.mlx = mlx_init(map.width * 50, map.height * 50, "MLX42", true);
	ft_elem_init(&map);
	ft_drawn_map(&map);
	ft_printf("player x is%i, player y is:%i\n", map.player_x, map.player_y);
	map.coints = map.collectable->count;
	mlx_loop_hook(map.mlx, &hook, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	ft_free_char_array(map.map_data);
	return (0);
}

void ft_drawn_line(t_map *map, int line)
{
	int j;
	char **m_data;
	t_map *tmp_map;

	tmp_map = map;
	m_data = map->map_data;
	j = 0;

	ft_printf("%s\n", m_data[line]);
	while (m_data[line][j] != '\0')
	{
		// ft_printf("y:%i x:%i\n",line, j);
		// ft_printf("%c", m_data[line][j]);
		if (m_data[line][j] == '0')
			mlx_image_to_window(map->mlx, map->space, ((j)*50), ((line)*50));
		else if (m_data[line][j] == '1')
			mlx_image_to_window(map->mlx, map->wall, ((j)*50), ((line)*50));
		else if (m_data[line][j] == 'C')
		{
			mlx_image_to_window(map->mlx, map->space, ((j)*50), ((line)*50));
			mlx_image_to_window(map->mlx, map->collectable, ((j)*50), ((line)*50));
		}
		else if (m_data[line][j] == 'P')
			mlx_image_to_window(map->mlx, map->space, ((j)*50), ((line)*50));
		else if (m_data[line][j] == 'E')
			mlx_image_to_window(map->mlx, map->exit, ((j)*50), ((line)*50));
		j++;
	}
}

void ft_drawn_player(t_map *map, int line)
{
	int j;
	char **m_data;
	m_data = map->map_data;
	j = 0;

	while (m_data[line][j] != '\0')
	{
		if (m_data[line][j] == 'P')
		{
			mlx_image_to_window(map->mlx, map->player, ((j)*50), ((line)*50));
			map->player_x = j;
			map->player_y = line;
		}
		j++;
	}
}

void ft_drawn_map(t_map *map)
{
	int i;
	i = 0;
	while (i < map->height)
	{
		ft_drawn_line(map, i);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		ft_drawn_player(map, i);
		i++;
	}
}

void ft_get_collectable(t_map *map)
{
	int i;

	i = 0;
	while (map->collectable->count > i)
	{
		if (map->collectable->instances[i].x == map->player->instances[0].x && map->collectable->instances[i].y == map->player->instances[0].y)
		{
			if (map->collectable->instances[i].enabled == true)
			{
				map->coints = map->coints - 1;
				map->collectable->instances[i].enabled = false;
			}
		}
		i++;
	}
}

void ft_free_char_array(char **str_str)
{
	int i;

	while (*str_str)
	{
		free(*str_str);
		str_str++;
	}
	return ;
}