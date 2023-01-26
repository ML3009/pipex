/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:36:32 by ml                #+#    #+#             */
/*   Updated: 2023/01/26 09:24:18 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void    ft_open_files(t_vars *var)
{
    var->infile = open(var->av[1], O_RDONLY);
    if (var->infile == -1)
    {
        ft_putstr_fd("Error : wrong input file", 2);
        exit(EXIT_FAILURE);
    }
    var->outfile = open(var->av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (var->outfile == -1)
    {
        ft_putstr_fd("Error : wrong onput file", 2);
        exit(EXIT_FAILURE);
    }
}

void    ft_create_pipe(t_vars *var)
{
    if (pipe (var->pipe_fd)== -1) // creation tube
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
}

void    ft_create_fork(t_vars *var)
{
    pid_t   cpid;
    char    buf;

    cpid = fork();
    if (cpid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
}

// utilisation de dup2 dans l'objectif de permettre communication entree et sortie entre les 2 commandes
void    ft_create_duplicate_cmd1(t_vars *var)
{
    dup2(var->cmd1, var->cmd1_v2);
    /*je veux creer STDIN et STDOUT de cmd1*/

}

void    ft_create_duplicate_cmd2(t_vars *var)
{
    dup2(var->cmd2, var->cmd2_v2);
    /*je veux creer STDIN et STDOUT de cmd2*/
}


/*    if (cpid == 0) //child lit dans le tube
    {
        close(var->pipe_fd[1]) // fermeture du descripteur en ecriture utilise
        while (read(pipe_fd[0], &buf, 1))
            write(STDOUT_FILENO, &buf, 1);
        write(STDOUT_FILENO)
*/
