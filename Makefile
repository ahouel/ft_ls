# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahouel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 10:03:32 by ahouel            #+#    #+#              #
#    Updated: 2019/04/30 18:29:48 by ahouel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = ./ft_ls

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/
LIB_PATH = ./libft/
LIB_INC = $(LIB_PATH)includes

SRC_FILES =	main.c			\
			parsing.c		\
			ft_ls.c			\
			stock_file.c	\
			apply_flags.c	\
			free_lst.c		\
			p_error.c		\
			output.c		\
			print_infos.c	\
			exit_error.c

INC_FILES = ft_ls.h	\
			ft_ls_struct.h
LIB_FILES = libft.a
LIB = $(addprefix $(LIB_PATH), $(LIB_FILES))

OBJ_NAMES = $(SRC_FILES:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_PATH), $(OBJ_NAMES))

all: $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH) -I $(LIB_INC)
	@echo "\033[34mCompilation of \033[1m$(notdir $<)\033[0m \033[34mdone.\033[0m"

$(LIB):
	@make -C $(LIB_PATH)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJ_FILES) $(addprefix $(INC_PATH), $(INC_FILES))
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIB) -o $(NAME) -I $(INC_PATH) -I $(LIB_PATH)includes
	@echo "\033[32mBinary \033[1;32m$(notdir $(NAME))\033[1;0m\033[32m created.\033[0m"

clean:
ifeq ("$(shell test -e $(OBJ_PATH) && echo titi)", "titi")
ifneq ($(SRC_PATH), $(OBJ_PATH))
	@rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files of \033[1;31m$(notdir $(NAME))\033[1;0m\033[31m removed.\033[0m"
else
	@echo "\033[31mSRC_PATH and OBJ_PATH shouldn't be the same, please change it\033[0m"
endif
	@make -C $(LIB_PATH) clean
else
	@echo "\033[31mObjects files of \033[1;31m$(notdir $(NAME))\033[1;0m\033[31m not found.\033[0m"
endif

fclean: clean
ifeq ("$(shell test -e $(NAME) && echo toto)", "toto")
	@rm $(NAME)
	@rm $(LIB)
	@echo "\033[31mBinary \033[1;31m$(notdir $(NAME))\033[1;0m\033[31m removed.\033[0m"
else
	@echo "\033[31mBinary \033[1;31m$(notdir $(NAME))\033[1;0m\033[31m not found.\033[0m"
endif

re: fclean all
