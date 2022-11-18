/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <coder@slaszlo-@student.42heib    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:10:40 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/18 14:28:26 by slaszlo-         ###   ########.fr       */
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
	mlx_image_t	*wall;
	mlx_image_t	*collectable;
	mlx_image_t	*exit;
	mlx_image_t	*player;
}	t_map;

//colors.c
int		get_rgba(int r, int g, int b, int a);
int		get_r(int rgba);
int		get_g(int rgba);
int		get_b(int rgba);
int		get_a(int rgba);

//error.c

bool	ft_check_elem(char *big_str);
bool	ft_sub_check_elem(int exit, int player, int collectable);
bool	ft_check_map(t_map *map);
bool	map_not_recktangle(t_map *map);
bool	map_incorrect_wall(t_map *map);
bool	flood_fill(char **data, t_map *map, int player_x, int player_y);
void	fill(char **tab, int height, int width, int x, int y);
void	ft_player_position(t_map *map);
void	ft_player_position_sub(t_map *map, int line);
bool	ft_map_noncompletable(char **map, int map_height);

//initialise.c

void	ft_map_init(t_map *map);
void	ft_map_dimentions(t_map *map, char *big_str);
void	ft_elem_init(t_map *map);
int		ft_get_with(char *big_str);
int		ft_get_height(char *big_str);

//map.c

void	ft_free_map(char **map, int lines);
void	ft_print_map(char **map, int lines);
char	**ft_get_map(char *argv[]);
int		ft_line(char *argv[]);

//characters.c

void	drawn_player(mlx_image_t *image);
void	drawn_block(mlx_image_t *image);
void	drawn_coin(mlx_image_t *image);
void	drawn_exit(mlx_image_t *image);
void	drawn_space(mlx_image_t *image);

//parcing.c

char	*ft_read_map(int fd);
char	**ft_get_map_2(char *argv[]);
int		ft_line_size(char *argv[]);
char	*ft_read_line(char *argv[]);
bool	ft_check_extention(char *argv1, char *extention);

#endif
