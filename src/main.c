/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:55:38 by ml                #+#    #+#             */
/*   Updated: 2023/02/15 15:01:34 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int ac, char **av, char **envp)
{
    t_vars   var;
    if(ac != 5)
        ft_putstr_fd("\nError : wrong numbers of arguments\n", 2);
    ft_init(&var, ac, av);
    ft_create_pipe(&var);
    ft_create_fork1(&var);
    if(var.child1 == 0)
    {
        ft_first_dup(&var);
        var.path_1 = ft_find_path(var.cmd_1, envp);
        execve(var.path_1, var.cmd_1, envp);
    }
    ft_create_fork2(&var);
    if(var.child2 == 0)
    {
        ft_second_dup(&var);
        var.path_2 = ft_find_path(var.cmd_2, envp);
        execve(var.path_2, var.cmd_2, envp);
    }
    close(var.pipe_fd[0]);
    close(var.pipe_fd[1]);
    waitpid(var.child1, NULL, 0);
    waitpid(var.child2, NULL, 0);
    return(0);
}
