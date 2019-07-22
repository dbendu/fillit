# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/14 19:26:20 by ymanilow          #+#    #+#              #
#    Updated: 2019/07/22 09:02:06 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fillit

SRCS =	fillit.c				\
		input.c					\
		shape_actions.c			\
		main.c

HEADERS =	-Iincludes			\
			-Ilibft/includes

OBJS =	fillit.o				\
		input.o					\
		main.o					\
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

f: fclean