/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:10:40 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/09 11:53:29 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
// Defines:
# define WIDTH 500
# define HEIGHT 500
# define MOVE 5

// Structs

typedef struct s_map
{
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	char	**map_data;
	int		steps;
	void	*mlx;
	void	*player;
}	t_map;
// map.c they leak like hell, I'll debug later

int		ft_line(char *argv[]);
char	**ft_get_map(char *argv[]);
void	ft_print_map(char **map, int lines);
void	ft_free_map(char **map, int lines);

//colors.c
int		get_rgba(int r, int g, int b, int a);
int		get_r(int rgba);
int		get_g(int rgba);
int		get_b(int rgba);
int		get_a(int rgba);

//drawn.c

void	drawn_player(mlx_image_t *image);
void	drawn_block(mlx_image_t *image);
void	drawn_coin(mlx_image_t *image);
void	drawn_exit(mlx_image_t *image);

#endif
