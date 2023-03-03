# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 16:27:10 by mvautrot          #+#    #+#              #
#    Updated: 2023/03/03 10:47:48 by mvautrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=cc
CFLAGS=-Wall -Wextra -Werror

SRC=ft_isalpha.c \
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_putendl.c\
	ft_putnbr.c\
	ft_unsign_nb.c\
	ft_hexa_min.c\
	ft_hexa_max.c\
	ft_putaddr.c\
	ft_printf.c\
	get_next_line.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_strcmp.c\
	ft_free_tab.c\
	ft_perror.c\

OBJ=$(SRC:.c=.o)

BONUS= ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\

OBJBONUS =$(BONUS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

all : $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

bonus : $(OBJ) $(OBJBONUS)
	ar rc $(NAME) $(OBJ) $(OBJBONUS)
