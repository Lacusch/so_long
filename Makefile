CC = cc
CFLAGS = -Wall -Wextra - Werror
NAME = so_long
LIBFT = libft/libft.a
MLX42 = MLX42/libmlx42.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42)

$(LIBFT):
	git submodule update --init --recursive --remote
	make -C ./libft
$(MLX42):
	git submodule update --init --recursive --remote
	make -C ./MLX42
clean:
	make clean -C ./libft
	make clean -C ./MLX42
fclean: clean
	make fclean -C ./libft
	make fclean -C ./MLX42
test:
	gcc main.c -o test ./MLX42/libmlx42.a -lglfw -L "/Users/slaszlo-/.brew/opt/glfw/lib/"
tclean:
	rm -rf test

.PHONY all clean fclean test tclean