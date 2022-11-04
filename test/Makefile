all: test
map: test
	./test map.ber
test:
	gcc -o test main.c ../libft/libft.a
clean:
	rm -rf test
.Phony:
	all test clean