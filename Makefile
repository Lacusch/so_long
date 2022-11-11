CC = cc
CFLAGS = -Wall -Wextra - Werror
NAME = so_long
LIBFT = libft/libft.a
MLX42 = MLX42/libmlx42.a
GLFW = -lglfw -L "/Users/slaszlo-/.brew/opt/glfw/lib/"

all: $(NAME)
	
$(NAME): $(LIBFT) $(MLX42)
	@echo "compliling $(NAME)"
	@gcc -o so_long src/characters.c \
	src/colors.c \
	src/drawn.c \
	src/initialise.c \
	src/main.c \
	src/map.c \
	src/parcing.c \
	libft/libft.a ./MLX42/libmlx42.a $(GLFW)
	@echo "$(NAME) compliling done"
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
t: tclean $(NAME)
	 ./so_long map/map.ber
re: fclean all

tclean:
	rm -rf $(NAME)
.PHONY: all clean fclean test tclean re