/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:36:32 by ml                #+#    #+#             */
/*   Updated: 2023/01/24 19:48:13 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void    ft_open_files(t_vars *vars)
{
    vars->infile = open(vars->av[1], O_RDONLY);
    if (vars->infile == -1)
    {
        ft_putstr_fd("Error : wrong input file", 2);
        exit(EXIT_FAILURE);
    }
    vars->outfile = open(vars->av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (vars->outfile == -1)
    {
        ft_putstr_fd("Error : wrong onput file", 2);
        exit(EXIT_FAILURE);
    }
}