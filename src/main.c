/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:55:38 by ml                #+#    #+#             */
/*   Updated: 2023/02/15 08:46:25 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int ac, char **av, char **envp)
{
    t_vars   var;
    int status;

    if(ac != 5)
        ft_putstr_fd("\nError : wrong numbers of arguments\n", 2);
    ft_init(&var, ac, av, envp);
    ft_create_pipe(&var);
    ft_create_fork1(&var);
    if(var.child1 == 0)
    {
        ft_printf ("Start of problem?");
        ft_first_dup(&var);
        ft_execute_cmd_1(&var);
    }
    else
    {
        if (waitpid(var.child1, &status, 0) == -1)
        {
            perror("\nwaitpid\n");
            exit(EXIT_FAILURE);
        }

    } /*else ? gestion process parent ?*/
    ft_create_fork2(&var);
    if(var.child2 == 0)
    {
        ft_second_dup(&var);
        ft_execute_cmd_2(&var);
    }
    else
    {
        if (waitpid(var.child2, &status, 0) == -1)
        {
            perror("\nwaitpid\n");
            exit(EXIT_FAILURE);
        }
    }
    close(var.pipe_fd[0]);
    close(var.pipe_fd[1]);
}
