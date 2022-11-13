/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:10:40 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/13 14:07:41 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
// Defines:

# define WIDTH 500
# define HEIGHT 500
# define MOVE 50
# define SIZE 48

// Structs
/*
@param height the height of the window
@param width the width of the window
@param player_x player x position
@param player_y player y position
@param map_data char** for map with the format [y][x]
@param steps the number of steps taken
@param mlx pointer to mlx
@param space image of space
@param wall image of wall
@param collectable image of collectable
@param exit image of exit
@param player image of player
*/
typedef struct s_map
{
	int			height;
	int			width;
	int			player_x;
	int			player_y;
	char		**map_data;
	int			steps;
	int			coints;
	void		*mlx;
	mlx_image_t	*space;
	mlx_image_t *wall;
	mlx_image_t *collectable;
	mlx_image_t *exit;
	mlx_image_t	*player;
}	t_map;

//colors.c
int		get_rgba(int r, int g, int b, int a);
int		get_r(int rgba);
int		get_g(int rgba);
int		get_b(int rgba);
int		get_a(int rgba);

//error.c

bool ft_check_elem(char *big_str);

//initialise.c

void	ft_map_init(t_map *map, char *big_str);
void ft_elem_init(t_map *map);
int ft_get_with(char* big_str);
int ft_get_height(char *big_str);
//characters.c

void	drawn_player(mlx_image_t *image);
void	drawn_block(mlx_image_t *image);
void	drawn_coin(mlx_image_t *image);
void	drawn_exit(mlx_image_t *image);
void	drawn_space(mlx_image_t *image);

//parcing.c

char	*ft_read_map(int fd);
char	**ft_get_map_2(char *argv[]);
int		ft_line_size (char *argv[]);
char	*ft_read_line(char *argv[]);
bool ft_check_extention(char* argv1, char *extention);

#endif
