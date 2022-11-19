CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
LIBFT = libft/libft.a
MLX42 = MLX42/libmlx42.a
GLFW = -lglfw -L "/Users/slaszlo-/.brew/opt/glfw/lib/"

all: $(NAME)
	
$(NAME): $(LIBFT) $(MLX42)
	@echo "compliling $(NAME)"
	@$(CC) $(CFLAGS) -o so_long src/characters.c \
	src/colors.c \
	src/error.c \
	src/error2.c \
	src/hook.c \
	src/initialise.c \
	src/main.c \
	src/map.c \
	src/move.c \
	src/parcing.c \
	src/size.c \
	src/utils.c \
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
t:
	 ./$(NAME) map/map.ber
t2:
	./$(NAME) map/big_map.ber
re: fclean all
tre: tclean $(NAME)
tclean:
	rm -rf $(NAME)
.PHONY: all clean fclean test tclean re