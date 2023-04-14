# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 09:59:07 by ml                #+#    #+#              #
#    Updated: 2023/03/07 12:15:25 by mvautrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

cc = cc

CFLAGS = -Wall -Werror -Wextra -g3

PATH_SRC = src
PATH_SRC_BONUS = src_bonus

PATH_LIB = libft

SRC = $(PATH_SRC)/ft_pipe.c\
	  $(PATH_SRC)/ft_path.c\
	  $(PATH_SRC)/main.c

SRC_BONUS = $(PATH_SRC_BONUS)/ft_pipe_bonus.c\
	  $(PATH_SRC_BONUS)/ft_path_bonus.c\
	  $(PATH_SRC_BONUS)/ft_here_doc.c\
	  $(PATH_SRC_BONUS)/ft_gestion.c\
	  $(PATH_SRC_BONUS)/main_bonus.c

LIB = $(PATH_LIB)/libft.a

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(LIB) $(NAME)

bonus : $(LIB) $(NAME_BONUS)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo "\n Compilation OK\n"

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIB)
	@echo "\n Compilation Bonus OK\n"

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB) :
	@make -s -C $(PATH_LIB)

clean :
	make -C $(PATH_LIB) clean
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean : clean
	make -C $(PATH_LIB) fclean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re
