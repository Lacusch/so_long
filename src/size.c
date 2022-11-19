/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:26:01 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/19 13:27:10 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

bool	ft_map_to_big(int x, int y)
{
	if (x > IMAC_RES_X || y > IMAC_RES_Y)
	{
		ft_printf("Error\n");
		if (x > IMAC_RES_X)
		{
			ft_printf("map width is:");
			ft_printf("%i but the display limit is:%i\n", x, IMAC_RES_X);
		}
		if (y > IMAC_RES_Y)
		{
			ft_printf("map height is:");
			ft_printf("%i but the display limit is:%i\n", y, IMAC_RES_Y);
		}
		return (1);
	}
	return (0);
}
