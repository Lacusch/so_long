/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:01:14 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/12 10:46:10 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

char* ft_read_map(int fd)
{
	int error;
	char *str;
	char *buf;
	
	str = calloc (1, 1);
	buf = malloc (100 + 1 * sizeof (char));
	while (error > 0)
	{
		error = read(fd, buf, 100);
		if (error <= 0)
			free (buf);
		if (error == 0)
			return (str);
		if (error < 0)
			return (NULL);
		buf[error] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	close(fd);
	return (str);
}

char	**ft_get_map_2(char *argv[])
{
	int		fd;
	int		i;
	char **str_array;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("the file desriptor is:%i\n", fd);
		return (NULL);
	}
	ft_split((const char *)ft_read_map(fd), '\n');
	return (str_array);
}

int ft_line_size (char *argv[])
{
	int		fd;
	char	*buff;
	int char_read;
	char_read = 0;
	buff = malloc (BUFFER_SIZE + 1 * sizeof (char));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("the file desriptor is:%i\n", fd);
		free(buff);
		return (-1);
	}
	char_read = read(fd, buff, BUFFER_SIZE);
	ft_printf("char read =%i\n", char_read);
	free (buff);
	close (fd);
	return(char_read);
}

char* ft_read_line(char *argv[], int char_read)
{
	int		fd;
	char	*buff;

	buff = malloc (char_read + 1 * sizeof (char));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("the file desriptor is:%i\n", fd);
		free(buff);
		return (NULL);
	}
	read(fd, buff, char_read);
	close (fd);
	ft_printf("the line is:\n%s", buff);
	return (buff);
}