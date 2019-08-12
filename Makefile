# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/14 19:26:20 by ymanilow          #+#    #+#              #
#    Updated: 2019/08/12 13:30:37 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fillit

SRCS =	main.c					\
		input.c					\
		fillit.c				\
		shape_actions.c

HEADERS =	-Iincludes			\
			-Ilibft/includes

OBJS =	main.o					\
		input.o					\
		fillit.o				\
		shape_actions.o			\
		libft/libft.a




all: $(NAME)


$(NAME):
	@make -C libft
	@gcc -Wall -Wextra -Werror -c $(SRCS) $(HEADERS)
	@gcc $(OBJS) -o $(NAME)


clean:
	@make clean -C libft
	@rm -f $(OBJS)


fclean: clean
	@rm -f $(NAME)


re: fclean all




c: clean


f: fclean


g:
	@make -g -C libft
	@gcc -g -Wall -Wextra -Werror -c $(SRCS) $(HEADERS)
	@gcc $(OBJS) -o $(NAME)