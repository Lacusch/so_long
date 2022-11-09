/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:06:57 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/09 12:36:18 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

void	hook(void *param)
{
	t_map *map;

	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
}
int	main(int argc, char *argv[])
{
	t_map	*map;
	map = malloc (sizeof(t_map *));
	mlx_image_t* background;
    mlx_image_t* blocks;
	mlx_image_t* coin;
	mlx_image_t* goal;

	map->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	// map.map_data = ft_get_map(argv);
	background = mlx_new_image(map->mlx, 500, 500);
	ft_memset(background->pixels, 255, background->width * background->height * sizeof(int));
	mlx_image_to_window(map->mlx, background, 0, 0);
	goal = mlx_new_image(map->mlx, 25, 25);
	drawn_exit(goal);
	mlx_image_to_window(map->mlx, goal, 0, 0);
	map->player = mlx_new_image(map->mlx, 25, 25);
	drawn_player(map->player);
	mlx_image_to_window(map->mlx, map->player, 50, 50);
	mlx_loop_hook(map->mlx, &hook, map);
    mlx_loop(map->mlx);
    mlx_terminate(map->mlx);
	return (0);
}
// int	main(int argc, char *argv[])
// {
// 	t_map *map;
// 	map = malloc (sizeof(t_map *));
// 	return (0);
// }