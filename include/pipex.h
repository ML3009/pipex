/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:54:32 by ml                #+#    #+#             */
/*   Updated: 2023/02/22 17:24:41 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_dil/libft.h"

typedef struct s_vars
{
    int ac;
    char    **av;
    char    **envp;
    char    *path;
    char    *path_1;
    char    *path_2;
    char    **cmd_1;
    char    **cmd_2;
    int infile;
    int outfile;
    int pipe_fd[2];
    pid_t child1;
    pid_t child2;
}   t_vars;

void    ft_init(t_vars *var, int ac, char **av, char **envp);
void    ft_create_pipe(t_vars *var);
void    ft_create_fork1(t_vars *var);
void    ft_create_fork2(t_vars *var);
void    ft_child1(t_vars *var);
void    ft_child2(t_vars *var);
void    ft_first_dup(t_vars *var);
void    ft_second_dup(t_vars *var);
void    ft_execute_cmd(t_vars *var);
char   *ft_find_path(char **cmd, char **envp);
