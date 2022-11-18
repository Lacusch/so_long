/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <coder@slaszlo-@student.42heib    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:43:33 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/18 14:49:54 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"

void	fill(char **tab, int height, int width, int x, int y)
{
	if (y < 0 || y >= height || x < 0 || x >= width)
		return ;
	if (tab[y][x] != '0' && tab[y][x] != 'C'
	&& tab[y][x] != 'P' && tab[y][x] != 'E')
		return ;
	tab[y][x] = 'F';
	fill(tab, height, width, x + 1, y);
	fill(tab, height, width, x - 1, y);
	fill(tab, height, width, x, y + 1);
	fill(tab, height, width, x, y - 1);
}

bool	flood_fill(char **data, t_map *map, int player_x, int player_y)
{
	fill(data, map->height, map->width, player_x, player_y);
	if (ft_completable_test(data, map->height) == true)
	{
		return (true);
		ft_free_map(data, map->height);
	}
	ft_free_map(data, map->height);
	return (false);
}

bool	ft_completable_test(char **map, int lines)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = map;
	i = 0;
	j = 0;
	while (i < lines)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
			{
				ft_printf("Error\nmap incompletable");
				return (true);
			}
		j++;
		}
		j = 0;
		i++;
	}
	return (false);
}

void	ft_player_position(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		ft_player_position_sub(map, i);
		i++;
	}
}

void	ft_player_position_sub(t_map *map, int line)
{
	int		j;
	char	**m_data;

	j = 0;
	m_data = map->map_data;
	while (m_data[line][j] != '\0')
	{
		if (m_data[line][j] == 'P')
		{
			map->player_x = j;
			map->player_y = line;
		}
		j++;
	}
}
