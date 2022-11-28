CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
LIBFT = lib/libft/libft.a
MLX42 = lib/MLX42/libmlx42.a
GLFW3 = ./lib/MLX42/glfw_lib/libglfw3.a
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
	lib/libft/libft.a lib/MLX42/libmlx42.a $(GLFW3) -framework Cocoa -framework OpenGL -framework IOKit
	@echo "$(NAME) compliling done"
$(LIBFT):
	make -C ./lib/libft/
$(MLX42):
	make -C ./lib/MLX42
$(GLFW3):
	@if [ -d ./lib/MLX42/glfw_lib ]; \
    then echo "./lib/MLX42/glfw_lib Exists"; \
    else \
	git submodule update --init --recursive --remote && \
	curl -LO https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.bin.MACOS.zip && \
    unzip glfw-3.3.8.bin.MACOS.zip && \
    rm glfw-3.3.8.bin.MACOS.zip && \
	mv glfw-3.3.8.bin.MACOS/lib-universal glfw-3.3.8.bin.MACOS/glfw_lib && \
	mv glfw-3.3.8.bin.MACOS/glfw_lib ./lib/MLX42/ && \
	mv glfw-3.3.8.bin.MACOS/include/GLFW lib/MLX42/include && \
	rm -rf glfw-3.3.8.bin.MACOS && \
	echo "doesn't exists"; \
	fi
clean:
	make clean -C  ./lib/libft
	make clean -C  ./lib/MLX42
fclean: clean
	make fclean -C  ./lib/libft
	make fclean -C  ./lib/MLX42
	rm -rf lib/MLX42/glfw_lib/ lib/MLX42/include/GLFW/

t: $(NAME)
	 ./$(NAME) map/map.ber
t2: $(NAME)
	./$(NAME) map/big_map.ber
re: fclean all
tre: tclean $(NAME)
tclean:
	rm -rf $(NAME)
.PHONY: all clean fclean test tclean re