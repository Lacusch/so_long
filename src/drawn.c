/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:06:59 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/06 16:44:30 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	drawn_block(mlx_image_t *image)
{
	mlx_image_t	*tmp;
	int			x;
	int			y;

	x = 0;
	y = 0;
	tmp = image;
	while (y < 50)
	{
		x = 0;
		while (x < 50)
		{
			mlx_put_pixel(image, x, y, 0x7f11e0);
			x++;
		}
		y++;
	}
}

void	drawn_stuff(mlx_image_t *image)
{
	mlx_image_t	*tmp;
	int			x;
	int			y;

	x = 0;
	y = 0;
	tmp = image;
	while (y < 25)
	{
		x = 0;
		while (x < 25)
		{
			mlx_put_pixel(image, x, y, 0x43ff64d9);
			x++;
		}
		y++;
	}
}
