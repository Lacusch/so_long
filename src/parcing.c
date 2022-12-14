/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:01:14 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/19 13:29:08 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_read_map(int fd)
{
	int		error;
	char	*str;
	char	*buf;

	error = 1;
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
	char	**str_array;

	str_array = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("the file desriptor is:%i\n", fd);
		return (NULL);
	}
	str_array = ft_split((const char *)ft_read_map(fd), '\n');
	return (str_array);
}

int	ft_line_size(char *argv[])
{
	int		fd;
	char	*buff;
	int		char_read;

	char_read = 0;
	buff = malloc ((BUFFER_SIZE + 1) * sizeof (char));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		free(buff);
		return (-1);
	}
	char_read = read(fd, buff, BUFFER_SIZE);
	ft_printf("char read =%i\n", char_read);
	free (buff);
	close (fd);
	return (char_read);
}

char	*ft_read_line(char *argv[])
{
	int		fd;
	char	*buf;
	int32_t	buflen;
	char	*line;

	buflen = 1;
	line = ft_calloc(1, 1);
	buf = malloc(30 + 1 * sizeof(char));
	fd = open(argv[1], O_RDONLY);
	while (buflen > 0)
	{
		buflen = read(fd, buf, 30);
		if (buflen <= 0)
			free (buf);
		if (buflen == 0)
			return (line);
		if (buflen < 0)
			return (NULL);
		buf[buflen] = '\0';
		line = ft_strjoin(line, buf);
	}
	close (fd);
	return (line);
}

bool	ft_check_extention(char *argv1, char *extention)
{
	int	file_lengt;
	int	extention_lenght;

	file_lengt = ft_strlen(argv1);
	extention_lenght = ft_strlen(extention);
	while (extention_lenght > 0)
	{
		if (argv1[file_lengt--] != extention[extention_lenght--])
		{
			ft_printf("Error\nWrong file extension");
			return (false);
		}
	}
	return (true);
}
