#include "../libft/libft.h"
#include <fcntl.h>

int ft_line(char *argv[]);

int main (int av, char *argv[])
{
	int fd;
	char **str_array;
	int i;
	t_list *list;
	char *tmp;

	// i = ft_line(argv);
	// ft_printf("the amount of lines is:%i\n", i);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("the file desriptor is:%i\n", fd);
		return (1);
	}
	tmp = get_next_line(fd);
	list->content = tmp;
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		list->next = ft_lstnew(tmp);
		list = list->next;
	}
	// str_array = malloc ((i + 1) * sizeof (char *));
	// *str_array = get_next_line(fd);
	// ft_printf("the string is :%s\n", *str_array);
	i = 0;
	return (0);
}

int ft_line(char *argv[])
{
	int i;
	char *tmp;
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("the file desriptor is:%i\n", fd);
		return (1);
	}
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
	// ft_printf("Line is:%s\n", tmp);
	tmp = get_next_line(fd);
	i++;
	}
	free(tmp);
	close(fd);
	return (i);
}