all:
	@clear
	@gcc -Wall -Werror -Wextra -Ilibft/includes *.c libft.a -o fillit

d:
	@clear
	@gcc -g -Wall -Werror -Wextra -Ilibft/includes main.c input.c shape.c solve.c libft.a -o fillit

c:
	@clear
	@gcc -Wall -Werror -Wextra -Ilibft/includes *.c libft.a -o fillit
	@./fillit file.txt
