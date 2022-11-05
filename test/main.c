#include "../libft/libft.h"
#include "../includes/so_long.h"

int main (int av, char *argv[])
{
	char **str_array;
	int lines;
	int i;

	i = 1;
	lines = ft_line(argv);
	str_array = ft_get_map(argv);
	ft_printf("lines :%i\n", lines);
	ft_print_map(str_array, lines);
	ft_free_map(str_array, lines);
	return (0);
}