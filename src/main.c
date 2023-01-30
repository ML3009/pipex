/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:55:38 by ml                #+#    #+#             */
/*   Updated: 2023/01/30 18:48:54 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int ac, char **av, char **envp)
{
    t_vars   var;

    if(ac != 5)
        ft_putstr_fd("Error : wrong numbers of arguments", 2);
    ft_init(&var, ac, av, envp);
    ft_create_pipe(&var);
    ft_create_fork1(&var);
    if(var.child1 == 0)
    {
        ft_first_dup(&var);
        ft_execute_cmd(&var);
    }     
    ft_create_fork2(&var);
    if(var.child2 == 0)
    {
        ft_second_dup(&var);
        ft_execute_cmd(&var);
    }  
    close(var.pipe_fd[0]);
    close(var.pipe_fd[1]); 
    waitpid(var.child1, NULL, 0); // attendre fin exec child process // evite process zombie
    waitpid(var.child2, NULL, 0); 
}
