/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:54:32 by ml                #+#    #+#             */
/*   Updated: 2023/01/31 16:19:37 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../lib_dil/libft.h"

typedef struct s_vars
{
    int ac;
    char    **av;
    char    **envp;
    char    *path;
    char    **cmd_path;
    char    **cmd_1;
    char    **cmd_2;
    int infile;
    int outfile;
    int pipe_fd[2];
    int child1;
    int child2;
}   t_vars;

void    ft_init(t_vars *var, int ac, char **av, char **envp);
void    ft_create_pipe(t_vars *var);
void    ft_create_fork1(t_vars *var);
void    ft_create_fork2(t_vars *var);
void    ft_first_dup(t_vars *var);
void    ft_second_dup(t_vars *var);
void    ft_execute_cmd(t_vars *var);
char   *ft_find_path_cmd_1(t_vars *var);
void    ft_execute_cmd_1(t_vars *var);
char    *ft_find_path_cmd_2(t_vars *var);
void    ft_execute_cmd_2(t_vars *var);
void	ft_free_tab(char **tab);
