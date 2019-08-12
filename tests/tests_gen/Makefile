# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/29 06:31:13 by sleonia           #+#    #+#              #
#    Updated: 2019/06/29 12:26:03 by sleonia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

#****************************************************************************#
#					SETTINGS FOR CONCLUSION IN CONSOLE 						 #
#****************************************************************************#

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
AQUA = \033[36m
GREY = \033[37m
UNDERLINE = \033[4m
NORMAL = \033[0m

#****************************************************************************#
#									TESTS 									 #
#****************************************************************************#

NAME = love_is

SRC_PATH = ./source/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
LIB_PATH = ./includes/libft/

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

SRC_NAME = main.c	 	\
		   option.c	 	\
		   difficult.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fillit_check.h

all: $(NAME)

$(NAME): $(OBJ)
	@make lib_refresh
	@gcc -o $(NAME) $(OBJ) -lm -L $(LIB_PATH) -lft
	@echo "\t\t      $(AQUA)ARE YOU READY FOR PAIN?!$(NORMAL)"
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc -Wall -Werror -Wextra $(INC) -o $@ -c $<

#****************************************************************************#
#									OTHER			 						 #
#****************************************************************************#

lib_refresh:
	@make -C $(LIB_PATH)

norm:
	@echo "$(YELLOW)"
	@norminette -R CheckForbiddenSourceHeader

clean:
	@clear
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "\t\t      $(GREEN)I DONT FEEL MY BINARY FILE!$(NORMAL)" 

re: fclean all
