#include "../libft/libft.h"
#include <fcntl.h>

int main (int av, char *argv[])
{
	int fd;
	char *str;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("the file desriptor is:%i\n", fd);
		return (1);
	}
	str = get_next_line(fd);
	if (str == NULL)
	{
		ft_printf("get_next_line didn't work\n");
		return (1);
	}
	while (str != NULL)
	{
	ft_printf("Line is:%s\n", str);
	str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (0);
}