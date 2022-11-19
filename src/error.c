/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:56:31 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/19 13:28:40 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	ft_check_elem(char *big_str)
{
	int	i;
	int	player;
	int	collectable;
	int	exit;

	i = 0;
	collectable = 0;
	exit = 0;
	player = 0;
	while (big_str[i])
	{
		if (big_str[i] == 'C')
			collectable++;
		if (big_str[i] == 'E')
			exit++;
		if (big_str[i] == 'P')
			player++;
		i++;
	}
	if (ft_sub_check_elem(exit, player, collectable) == true)
		return (false);
	return (true);
}

bool	ft_sub_check_elem(int exit, int player, int collectable)
{
	if (exit == 0)
		ft_printf("Error\nNo exit");
	else if (exit > 1)
		ft_printf("Error\nTo many exits");
	else if (player == 0)
		ft_printf("Error\nNo player");
	else if (player > 1)
		ft_printf ("Error\nTo many players");
	else if (collectable == 0)
		ft_printf("Error\nNot collectable");
	if (player != 1 || exit != 1 || collectable == 0)
		return (1);
	return (0);
}

bool	ft_check_map(t_map *map)
{
	if (map_incorrect_wall(map) == true || map_not_recktangle(map) == true)
		return (true);
	return (false);
}

bool	map_not_recktangle(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_data[i])
	{
		if ((int)ft_strlen(map->map_data[i]) != map->width)
		{
			ft_printf("Error\nNot recktengle");
			return (true);
		}
		i++;
	}
	return (false);
}

bool	map_incorrect_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map_data[0][i] != '1' ||
		map->map_data[map->height - 1][i] != '1')
		{
			ft_printf("Error\nIncorrect Wall");
			return (true);
		}
		i++;
	}
	i = 0;
	while (map->map_data[i])
	{
		if (map->map_data[i][0] != '1' ||
		map->map_data[i][map->width - 1] != '1')
		{
			ft_printf("Error\nIncorrect Wall");
			return (true);
		}
		i++;
	}
	return (false);
}
