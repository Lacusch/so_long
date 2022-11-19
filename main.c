/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:40:08 by W2Wizard          #+#    #+#             */
/*   Updated: 2022/11/19 11:21:49 by slaszlo-         ###   ########.fr       */
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

static void	hook(void *param)
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

int32_t	main(int ac, char **argv)
{
	printf("test\n");
    return (EXIT_SUCCESS);
}

