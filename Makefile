# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 09:59:07 by ml                #+#    #+#              #
#    Updated: 2023/02/20 14:05:42 by mvautrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

cc = @cc

CFLAGS = -Wall -Werror -Wextra -g3

PATH_SRC = src

PATH_LIB = lib_dil

SRC = $(PATH_SRC)/ft_gestion.c\
	  $(PATH_SRC)/ft_pipe.c\
	  $(PATH_SRC)/ft_path.c\
	  $(PATH_SRC)/main.c

LIB = $(PATH_LIB)/libft.a

OBJ = $(SRC:.c=.o)

all : $(LIB) $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo "\n Compilation OK\n"

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB) :
	@make -s -C $(PATH_LIB)

clean :
	make -C $(PATH_LIB) clean
	rm -f $(OBJ)

fclean : clean
	make -C $(PATH_LIB) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
