/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:36:32 by ml                #+#    #+#             */
/*   Updated: 2023/02/22 17:20:53 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void    ft_create_pipe(t_vars *var)
{
    if (pipe (var->pipe_fd)== -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
}

void    ft_create_fork1(t_vars *var)
{

    var->child1 = fork();
    if (var->child1 == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
}

void    ft_child1(t_vars *var)
{
    if (var->child1 == 0)
    {
        ft_first_dup(var);
        if (var->av[2][0] == '/')
            var->path_1 = &var->av[2][0];
        else
            var->path_1 = ft_find_path(var->cmd_1, var->envp);
        if (var->path_1)
            execve(var->path_1, var->cmd_1, var->envp);
    }
}

void    ft_first_dup(t_vars *var)
{
    var->infile = open(var->av[1], O_RDONLY);
    if (var->infile == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    if (dup2(var->pipe_fd[1], STDOUT_FILENO) == -1)
    {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
    if (dup2(var->infile, STDIN_FILENO) == -1)
    {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
    close(var->pipe_fd[0]);
    close(var->infile);
    close(var->pipe_fd[1]);
}

