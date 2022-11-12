/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:25:32 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/12 12:23:17 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

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
	tmp->mlx = NULL;
	tmp->space = NULL;
	tmp->wall = NULL;
	tmp->collectable = NULL;
	tmp->exit = NULL;
	tmp->player = NULL;
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
