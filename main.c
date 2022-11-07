/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:40:08 by W2Wizard          #+#    #+#             */
/*   Updated: 2022/11/07 14:12:47 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"
#include "libft/libft.h"
#include "./includes/so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_Q))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		g_img->instances[0].y -= MOVE;
		ft_printf("x is :%i, y is:%i\n", g_img->instances->x, g_img->instances->y);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	{
		g_img->instances[0].y += MOVE;
		ft_printf("x is :%i, y is:%i\n", g_img->instances->x, g_img->instances->y);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		g_img->instances[0].x -= MOVE;
		ft_printf("x is :%i, y is:%i\n", g_img->instances->x, g_img->instances->y);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		g_img->instances[0].x += MOVE;
		ft_printf("x is :%i, y is:%i\n", g_img->instances->x, g_img->instances->y);
	}
		if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		g_img->instances[0].y -= MOVE;
		ft_printf("x is :%i, y is:%i\n", g_img->instances->x, g_img->instances->y);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		g_img->instances[0].y += MOVE;
		ft_printf("x is :%i, y is:%i\n", g_img->instances->x, g_img->instances->y);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		g_img->instances[0].x -= MOVE;
		ft_printf("x is :%i, y is:%i\n", g_img->instances->x, g_img->instances->y);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		g_img->instances[0].x += MOVE;
		ft_printf("x is :%i, y is:%i\n", g_img->instances->x, g_img->instances->y);
	}
}

// Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
#define BPP sizeof(int32_t)
int32_t	main(int ac, char **argv)
{
	t_map map;
    mlx_t* mlx;
	mlx_image_t* background;
    mlx_image_t* blocks;
	mlx_image_t* coin;
	mlx_image_t* goal;
	map.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
    if (!mlx) exit(EXIT_FAILURE);

	background = mlx_new_image(map.mlx, 500, 500);
	memset(background->pixels, 255, background->width * background->height * sizeof(int));
	mlx_image_to_window(map.mlx, background, 0, 0);
	goal = mlx_new_image(map.mlx, 25, 25);
	blocks = mlx_new_image(map.mlx, 50, 50);
	coin = mlx_new_image(map.mlx, 50, 50);
	drawn_coin(coin);
	drawn_block(blocks);
	drawn_exit(goal);
    mlx_image_to_window(map.mlx, blocks, 0, 0);
    mlx_image_to_window(map.mlx, blocks, 0, 50);
	mlx_image_to_window(map.mlx, coin, 50, 50);
	mlx_image_to_window(map.mlx, goal, 50, 100);
	g_img = mlx_new_image(map.mlx, 25, 25);
	drawn_player(g_img);
	mlx_image_to_window(map.mlx, g_img, 10, 10);
	// mlx_image_to_window(mlx, coin, 100, 100);
    // Run the main loop and terminate on quit.
	mlx_loop_hook(map.mlx, &hook, map.mlx);
    mlx_loop(map.mlx);
    mlx_terminate(map.mlx);
    return (EXIT_SUCCESS);
}

