/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:46:38 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/11 10:25:54 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

/*
 The map can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position
*/

/*
Stuff to drawn:
	0 for an empty space
	1 for a wall,
	C for a collectible,
	E for a map exit,
	P for the player’s starting position.
*/
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
			mlx_put_pixel(image, x, y, get_rgba(0, 0, 0, 255));
			x++;
		}
		y++;
	}
}

void	drawn_player(mlx_image_t *image)
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
			mlx_put_pixel(image, x, y, 0x7f11e0);
			x++;
		}
		y++;
	}
}

void	drawn_coin(mlx_image_t *image)
{
	mlx_image_t	*tmp;
	int			x;
	int			y;

	x = 0;
	y = 0;
	tmp = image;
	ft_memset(image->pixels, 255, 50 * 50 *(sizeof(int)));
	while (y < 25)
	{
		x = 0;
		while (x < 25)
		{
			mlx_put_pixel(image, x, y, 0xf5f327cc);
			x++;
		}
		y++;
	}
}

void	drawn_exit(mlx_image_t *image)
{
	mlx_image_t	*tmp;
	int			x;
	int			y;

	x = 0;
	y = 0;
	tmp = image;
	ft_memset(image->pixels, 255, 50 * 50 *(sizeof(int)));
	while (y < 25)
	{
		x = 0;
		while (x < 25)
		{
			mlx_put_pixel(image, x, y, get_rgba(255, 0, 0, 255));
			x++;
		}
		y++;
	}
}

void	drawn_space(mlx_image_t *image)
{
	mlx_image_t	*tmp;
	int			x;
	int			y;

	x = 0;
	y = 0;
	tmp = image;
	ft_memset(image->pixels, 255, 50 * 50 *(sizeof(int)));
	while (y < 50)
	{
		x = 0;
		while (x < 50)
		{
			mlx_put_pixel(image, x, y, 255);
			x++;
		}
		y++;
	}
}
