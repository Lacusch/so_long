/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:10:01 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/11 10:29:15 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

void	ft_free_map(char **map, int lines)
{
	int	i;

	i = 1;
	while (i != (lines + 1))
	{
		free(map[i]);
		i++;
	}
	free (map);
}

void	ft_print_map(char **map, int lines)
{
	int		i;
	char	**tmp;

	tmp = map;
	i = 1;
	while (i < (lines + 1))
	{
		ft_printf("Line is:%s\n", tmp[i]);
		i++;
	}
}

char	**ft_get_map(char *argv[])
{
	char	**str_array;
	int		lines;
	char	*tmp;
	int		fd;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("the file desriptor is:%i\n", fd);
		return (NULL);
	}
	lines = ft_line(argv);
	str_array = malloc((lines + 1) * sizeof(char *));
	i = 1;
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
	str_array[i] = malloc(sizeof(char *));
	str_array[i] = tmp;
	tmp = get_next_line(fd);
	i++;
	}
	return (str_array);
}

int	ft_line(char *argv[])
{
	int		i;
	char	*tmp;
	int		fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("the file desriptor is:%i\n", fd);
		return (1);
	}
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
	tmp = get_next_line(fd);
	i++;
	}
	free(tmp);
	close(fd);
	return (i);
}
