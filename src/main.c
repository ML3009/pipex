/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:55:38 by ml                #+#    #+#             */
/*   Updated: 2023/02/22 17:19:53 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int ac, char **av, char **envp)
{
    t_vars   var;
    if(ac != 5)
        ft_putstr_fd("\nError : wrong numbers of arguments\n", 2);
    ft_init(&var, ac, av, envp);
    ft_create_pipe(&var);
    ft_create_fork1(&var);
    ft_child1(&var);
    ft_create_fork2(&var);
    ft_child2(&var);
    close(var.pipe_fd[0]);
    close(var.pipe_fd[1]);
    ft_free_tab(var.cmd_1);
    ft_free_tab(var.cmd_2);
    waitpid(var.child1, NULL, 0);
    waitpid(var.child2, NULL, 0);
    return(0);
}
