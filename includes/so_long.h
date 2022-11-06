/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:10:40 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/06 13:12:26 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

// Defines:
#define WIDTH 500
#define HEIGHT 500
#define MOVE 5

// Structs

typedef struct s_map
{
	int height;
	int width;
	int player_x;
	int player_y;
	char **map_data;
	int steps;
} t_map;
// map.c they leak like hell, I'll debug later

int ft_line(char *argv[]);
char **ft_get_map(char *argv[]);
void ft_print_map (char **map, int lines);
void ft_free_map (char **map, int lines);

//colors.c
int	get_rgba(int r, int g, int b, int a);
int	get_r(int rgba);
int	get_g(int rgba);
int	get_b(int rgba);
int	get_a(int rgba);
