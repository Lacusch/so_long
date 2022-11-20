CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
LIBFT = lib/libft/libft.a
MLX42 = lib/MLX42/libmlx42.a
GLFW3 = ./lib/MLX42/lib/
all: $(NAME)
	
$(NAME):$(GLFW3) $(LIBFT) $(MLX42)
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
	lib/libft/libft.a lib/MLX42/libmlx42.a -I include -lglfw -L "/Users/$USER/.brew/opt/glfw/lib/"
	@echo "$(NAME) compliling done"
$(LIBFT):
	make -C ./lib/libft/
$(MLX42):
	make -C ./lib/MLX42
$(GLFW3):
	git submodule update --init --recursive --remote
clean:
	make clean -C  ./lib/libft
	make clean -C  ./lib/MLX42
fclean: clean
	make fclean -C  ./lib/libft
	make fclean -C  ./lib/MLX42
	rm -rf lib/MLX42/glfw_lib/ lib/MLX42/include/GLFW/

t:
	 ./$(NAME) map/map.ber
t2:
	./$(NAME) map/big_map.ber
re: fclean all
tre: tclean $(NAME)
tclean:
	rm -rf $(NAME)
.PHONY: all clean fclean test tclean re