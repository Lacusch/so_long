/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:40:08 by W2Wizard          #+#    #+#             */
/*   Updated: 2022/11/06 13:12:41 by slaszlo-         ###   ########.fr       */
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
	
}

// Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
#define BPP sizeof(int32_t)
int32_t	main(int ac, char **argv)
{
	t_map map;

    // Init mlx with a canvas size of 256x256 and the ability to resize the window.v
    mlx_t* mlx;
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
    if (!mlx) exit(EXIT_FAILURE);

    // Create a 128x128 image.
    mlx_image_t* img = mlx_new_image(mlx, 50, 50);

    // Set the channels of each pixel in our image to the maximum byte value of 255. 
    memset(img->pixels, 255, img->width * img->height * BPP);
    // Draw the image at coordinate (0, 0).
    mlx_image_to_window(mlx, img, 0, 0);
	mlx_image_to_window(mlx, img, 0, 50);
	mlx_image_to_window(mlx, img, 50, 0);
	mlx_image_to_window(mlx, img, 50, 50);
	mlx_image_to_window(mlx, img, 100, 50);
	mlx_image_to_window(mlx, img, 100, 100);
	mlx_image_to_window(mlx, img, 50, 100);
	g_img = mlx_new_image(mlx, 25, 25);
	memset(g_img->pixels, 123, g_img->width * g_img->height * sizeof(int));
	mlx_put_pixel(g_img, 1, 1, 0xFF0000FF);
	mlx_image_to_window(mlx, g_img, 10, 10);
    // Run the main loop and terminate on quit.
	mlx_loop_hook(mlx, &hook, mlx);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}
