/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:52:04 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/19 10:07:42 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"

void	ft_drawn_line(t_map *map, int line)
{
	int		j;
	char	**m_data;
	t_map	*tmp_map;

	tmp_map = map;
	m_data = map->map_data;
	j = 0;
	ft_printf("%s\n", m_data[line]);
	while (m_data[line][j] != '\0')
	{
		if (m_data[line][j] == '0')
		{
			mlx_image_to_window(map->mlx, map->space, ((j) * 50), ((line) * 50));
		}
		else if (m_data[line][j] == '1')
			mlx_image_to_window(map->mlx, map->wall, ((j) * 50), ((line) * 50));
		else if (m_data[line][j] == 'C')
		{
			mlx_image_to_window(map->mlx, map->space, ((j) * 50), ((line) * 50));
			mlx_image_to_window(map->mlx, map->collectable, ((j) * 50), ((line) * 50));
		}
		else if (m_data[line][j] == 'P')
			mlx_image_to_window(map->mlx, map->space, ((j) * 50), ((line) * 50));
		else if (m_data[line][j] == 'E')
			mlx_image_to_window(map->mlx, map->exit, ((j) * 50), ((line) * 50));
		j++;
	}
}

void	ft_drawn_player(t_map *map, int line)
{
	int		j;
	char	**m_data;

	j = 0;
	m_data = map->map_data;
	while (m_data[line][j] != '\0')
	{
		if (m_data[line][j] == 'P')
		{
			mlx_image_to_window(map->mlx, map->player,
				((j) * 50), ((line) * 50));
			map->player_x = j;
			map->player_y = line;
		}
		j++;
	}
}

void	ft_drawn_map(t_map *map)
{
	int	i;

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

void	ft_get_collectable(t_map *map)
{
	int	i;

	i = 0;
	while (map->collectable->count > i)
	{
		if (map->collectable->instances[i].x == map->player->instances[0].x
			&& map->collectable->instances[i].y == map->player->instances[0].y)
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

void	ft_free_char_array(char **str_str)
{
	int	i;

	while (*str_str)
	{
		free(*str_str);
		str_str++;
	}
	return ;
}
