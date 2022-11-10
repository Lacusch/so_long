/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:06:57 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/10 15:53:12 by slaszlo-         ###   ########.fr       */
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
		map->player->instances[0].y -= MOVE;
		map->steps ++;
		ft_printf("The number of stepst is:%i\n", map->steps);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
	{
		map->player->instances[0].y += MOVE;
		map->steps ++;
		ft_printf("The number of stepst is:%i\n", map->steps);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
	{
		map->player->instances[0].x -= MOVE;
		map->steps ++;
		ft_printf("The number of stepst is:%i\n", map->steps);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
	{
		map->player->instances[0].x += MOVE;
		map->steps ++;
		ft_printf("The number of stepst is:%i\n", map->steps);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_P))
		ft_printf("Z data is:%i\n", map->player->instances->z);
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	int		i;

	i = 1;
	map = malloc (sizeof(t_map *));
	ft_map_init(map);
	map->map_data = ft_get_map(argv);
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
	t_map * tmp_map;
	tmp_map = map;
	m_data = map_data;
	j = 0;

	while (m_data[line][j] != '\0')
	{
		ft_printf("%c", m_data[line][j]);
		if (m_data[line][j] == '0')
			mlx_image_to_window(map->mlx, map->space, (j * 50), ((line -1) * 50));
		else if (m_data[line][j] == '1')
			mlx_image_to_window(map->mlx, map->wall, (j * 50), ((line -1) * 50));
		else if (m_data[line][j] == 'C')
			mlx_image_to_window(map->mlx, map->collectable, (j * 50), ((line -1) * 50));
		else if (m_data[line][j] == 'P')
		{
			mlx_image_to_window(map->mlx, map->player, (j * 50), ((line -1) * 50));
		}
		j++;
	}
}

void ft_drawn_map (char **map_data, t_map *map, int line)
{

}