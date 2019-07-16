all:
	@clear
	@gcc -Wall -Werror -Wextra -Ilibft/includes *.c libft.a

d:
	@clear
	@gcc -g -Wall -Werror -Wextra -Ilibft/includes *.c libft.a

c:
	@clear
	@gcc -Wall -Werror -Wextra -Ilibft/includes *.c libft.a
	@./a.out
