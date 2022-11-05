/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:10:40 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/05 13:14:38 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

// map.c they leak like hell, I'll debug later

int ft_line(char *argv[]);
char **ft_get_map(char *argv[]);
void ft_print_map (char **map, int lines);
void ft_free_map (char **map, int lines);
