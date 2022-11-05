all: test
map: re test
	./test map.ber
test:
	gcc -o test main.c ../libft/libft.a ../src/map.c
re: clean all
clean:
	@rm -rf test
.Phony:
	all test clean