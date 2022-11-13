/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:56:31 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/13 14:28:26 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"

bool ft_sub_check_elem(int exit, int player, int collectable);

bool ft_check_elem(char *big_str)
{
	int i;

	int player;
	int collectable;
	int exit;
	i = 0;
	collectable = 0;
	exit= 0;
	player = 0;
	while (big_str[i])
	{
		if (big_str[i] == 'C')
			collectable++;
		if (big_str[i] == 'E')
			exit++;
		if (big_str[i] == 'P')
			player++;
		i++;
	}
	if (ft_sub_check_elem(exit, player, collectable) == false)
		return (true);
	return (false);
}

bool ft_sub_check_elem(int exit, int player, int collectable)
{
	if (exit == 0)
		ft_printf("Error\nNo exit");
	else if (exit > 1)
		ft_printf("Error\nTo many exits");
	else if (player == 0)
		ft_printf("Error\nNo player");
	else if (player > 1)
		ft_printf ("Error\nTo many players");
	else if (collectable == 0)
		ft_printf("Error\nNot collectable");
	if (player != 1 || exit != 1 || collectable == 0)
		return (1);
	return (0);
}