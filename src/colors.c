/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:14:30 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/06 12:19:13 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
'Encodes' four individual bytes into an int.
@param r red color
@param g green color
@param b blue color
@param a alpha /transparancy
*/
int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// Get the red channel.
// Move 3 bytes to the right and mask out the first byte.
int	get_r(int rgba)
{
	return ((rgba >> 24) & 0xFF);
}

// Get the green channel.
// Move 2 bytes to the right and mask out the first byte.
int	get_g(int rgba)
{
	return ((rgba >> 16) & 0xFF);
}

// Get the blue channel.
// Move 1 byte to the right and mask out the first byte.
int	get_b(int rgba)
{
	return ((rgba >> 8) & 0xFF);
}

// Get the alpha channel.
// Move 0 bytes to the right and mask out the first byte.

int	get_a(int rgba)
{
	return (rgba & 0xFF);
}
