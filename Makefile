CC = cc
CFLAGS = -Wall -Wextra - Werror
NAME = so_long
LIBFT = libft/libft.a
MLX42 = MLX42/libmlx42.a
GLFW = -lglfw -L "/Users/slaszlo-/.brew/opt/glfw/lib/"
all: $(NAME)
	
$(NAME): $(LIBFT) $(MLX42)
	gcc -o so_long src/main.c src/map.c src/colors.c src/drawn.c libft/libft.a ./MLX42/libmlx42.a $(GLFW)
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
re: fclean all
test:
	gcc -o test.o main.c src/map.c src/colors.c src/drawn.c libft/libft.a ./MLX42/libmlx42.a $(GLFW)
tclean:
	rm -rf test
.PHONY: all clean fclean test tclean re