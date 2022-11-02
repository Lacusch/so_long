CC = cc
CFLAGS = -Wall -Wextra - Werror
NAME = so_long
LIBFT = libft/libft.a
MLX42 = MLX42/libmlx42.a
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
all: $(NAME)