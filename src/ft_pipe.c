/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:36:32 by ml                #+#    #+#             */
/*   Updated: 2023/02/22 16:45:10 by mvautrot         ###   ########.fr       */
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

//void    ft_child1(t_vars *var)
//{
 //   if (var->child1 == 0)

//}

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

void    ft_create_fork2(t_vars *var)
{

    var->child2 = fork();
    if (var->child2 == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
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
