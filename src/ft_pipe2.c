/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:20:42 by mvautrot          #+#    #+#             */
/*   Updated: 2023/02/22 17:22:15 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void    ft_create_fork2(t_vars *var)
{

    var->child2 = fork();
    if (var->child2 == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
}

void    ft_child2(t_vars *var)
{
    if (var->child2 == 0)
    {
        ft_second_dup(var);
        if (var->av[3][0] == '/')
            var->path_2 = &var->av[3][0];
        else
            var->path_2 = ft_find_path(var->cmd_2, var->envp);
        if (var->path_2)
            execve(var->path_2, var->cmd_2, var->envp);
    }
}

void    ft_second_dup(t_vars *var)
{
    var->outfile = open(var->av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (var->outfile == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    if (dup2(var->pipe_fd[0], STDIN_FILENO) == -1)
    {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
    if (dup2(var->outfile, STDOUT_FILENO) == -1)
    {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
    close(var->pipe_fd[1]);
    close(var->outfile);
    close(var->pipe_fd[0]);
}
