/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:25:32 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/19 13:28:51 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_map_init(t_map *map)
{
	t_map	*tmp;

	tmp = map;
	tmp->height = 0;
	tmp->width = 0;
	tmp->player_x = 0;
	tmp->player_y = 0;
	tmp->map_data = NULL;
	tmp->steps = 0;
	tmp->coints = 0;
	tmp->mlx = NULL;
	tmp->space = NULL;
	tmp->wall = NULL;
	tmp->collectable = NULL;
	tmp->exit = NULL;
	tmp->player = NULL;
}

void	ft_map_dimentions(t_map *map, char *big_str)
{
	t_map	*tmp;

	tmp = map;
	tmp->height = ft_get_height(big_str) / ft_get_with(big_str);
	tmp->width = ft_get_with(big_str);
}

void	ft_elem_init(t_map *map)
{
	t_map	*tmp;

	tmp = map;
	tmp->space = mlx_new_image(tmp->mlx, 50, 50);
	ft_memset(tmp->space->pixels, 255, 50 * 50 *(sizeof(int)));
	tmp->wall = mlx_new_image(tmp->mlx, 50, 50);
	drawn_block(map->wall);
	tmp->collectable = mlx_new_image(tmp->mlx, 50, 50);
	drawn_coin(tmp->collectable);
	tmp->player = mlx_new_image(tmp->mlx, 50, 50);
	drawn_player(tmp->player);
	tmp->exit = mlx_new_image(map->mlx, 50, 50);
	drawn_exit(tmp->exit);
}

int	ft_get_with(char *big_str)
{
	int	size;

	size = 0;
	while (big_str[size] != '\n')
		size++;
	return (size);
}

int	ft_get_height(char *big_str)
{
	int	size;

	size = 0;
	while (big_str[size] != '\0')
	{
		size++;
	}
	return (size);
}
