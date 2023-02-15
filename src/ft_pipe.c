/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:36:32 by ml                #+#    #+#             */
/*   Updated: 2023/02/15 08:27:56 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// creation du tube

void    ft_create_pipe(t_vars *var)
{
    if (pipe (var->pipe_fd)== -1) // creation tube
    {
        perror("\npipe\n");
        exit(EXIT_FAILURE);
    }
}

// creation du fork qui duplique le processus apelant(parent process) en child process.
void    ft_create_fork1(t_vars *var)
{

    var->child1 = fork();
    if (var->child1 == -1)
    {
        perror("\nfork1\n");
        exit(EXIT_FAILURE);
    }
}

void    ft_first_dup(t_vars *var)
{
    var->infile = open(var->av[1], O_RDONLY | O_CREAT);
    if (var->infile == -1)
    {
        ft_putstr_fd("\nError : wrong input file\n", 2);
        exit(EXIT_FAILURE);
    }
    ft_printf ("Start of problem");
    if (dup2(var->pipe_fd[1], STDOUT_FILENO) == -1)
    {
        perror("\ndup2_firstcmd 1\n");
        exit(EXIT_FAILURE);
    }
    if (dup2(var->infile, STDIN_FILENO) == -1)
    {
        perror("\ndup2_firstcmd 0\n");
        exit(EXIT_FAILURE);
    }
    close(var->pipe_fd[0]);
   // close(var->infile);
}

void    ft_create_fork2(t_vars *var)
{

    var->child2 = fork();
    if (var->child2 == -1)
    {
        perror("\nfork2\n");
        exit(EXIT_FAILURE);
    }
}

void    ft_second_dup(t_vars *var)
{
    var->outfile = open(var->av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (var->outfile == -1)
    {
        ft_putstr_fd("\nError : wrong onput file\n", 2);
        exit(EXIT_FAILURE);
    }
    if (dup2(var->pipe_fd[0], STDIN_FILENO) == -1)
    {
        perror("\ndup2_scdcmd 0\n");
        exit(EXIT_FAILURE);
    }
    if (dup2(var->outfile, STDOUT_FILENO) == -1)
    {
        perror("\ndup2_scdcmd 1\n");
        exit(EXIT_FAILURE);
    }
    close(var->pipe_fd[1]);
    close(var->outfile);
    close(var->pipe_fd[0]);
}
