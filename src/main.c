/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:55:38 by ml                #+#    #+#             */
/*   Updated: 2023/01/24 19:51:08 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int ac, char **av, char **envp)
{
    t_vars   vars;

    if(ac != 5)
        ft_putstr_fd("Error : wrong numbers of arguments", 2);
    ft_open_files(&vars);
    ft_init(&vars, ac, av, envp);
}