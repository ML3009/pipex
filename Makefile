# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ml <ml@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 09:59:07 by ml                #+#    #+#              #
#    Updated: 2023/01/20 10:07:05 by ml               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

cc = @cc

CFLAGS = -Wall -Werror -Wextra -g3

PATH_SRC = src

PATH_LIB = lib_dil

SRC = $(PATH_SRC)/pipe.c\
	  $(PATH_SRC)/child.c\
	  $(PATH_SRC)/parent.c\
	  $(PATH_SRC)/execve.c\
	  
LIB = $(PATH_LIB)/libft.a

OBJ = $(SRC:.c=.o)

all : $(LIB) $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) src/main.c -o $(NAME) $(OBJ) $(LIB)
	@echo "\n Compilation OK\n"

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB) :
	@make -s -C $(PATH_LIB)

clean :
	make - C $(PATH_LIB) clean
	rm -f $(OBJ)

fclean : clean
	make -C $(PATH_LIB) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclen re
	