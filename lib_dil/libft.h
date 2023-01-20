/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:25:31 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/19 10:33:33 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// LIBFT

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_memmove(void *dest, void *src, size_t n);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
size_t	ft_strlcat(char *dst, char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr( char *s, int c);
char	*ft_strrchr( char *s, int c);
int		ft_strncmp( char *s1, char *s2, size_t n);
int		ft_strcmp( char *s1, char *s2);
void	*ft_memchr( void *s, int c, size_t n);
int		ft_memcmp( void *s1, void *s2, size_t n);
char	*ft_strnstr( char *big, char *little, size_t len);
int		ft_atoi( char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup( char *s);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
char	**ft_split( char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putendl(char *s);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//GET NEXT LINE

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *line, char *buf);
char	*ft_check_line(char *line);
char	*ft_getlast_line(char *line, char *buf);

// PRINTF
int		ft_printf(const char *str_arg, ...);
int		ft_convert_arg( char str_arg, va_list ptr);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_unsign_nb(unsigned int nb);
int		ft_hexa_min(unsigned int nb);
int		ft_hexa_max(unsigned int nb);
int		ft_putaddr(uintptr_t nb);
int		ft_hexa_ptr(unsigned long long nb);
int		ft_strlen( char *str);

#endif
