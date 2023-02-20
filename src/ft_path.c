/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:43:48 by ml                #+#    #+#             */
/*   Updated: 2023/02/20 16:36:49 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char   *ft_find_path(char **cmd, char **envp)
{
    int i;
    char    *join;
    char    *search;
    char    **cmd_path;

    i = 0;
    while(ft_strncmp("PATH", envp[i], 4))
        i++;
    cmd_path = ft_split(envp[i] + 5, ':');
    i = 0;
    while (cmd_path[i])
    {
        join = ft_strjoin(cmd_path[i], "/");
        search = ft_strjoin(join, cmd[0]);
        //free(join);
        if (access(search, F_OK) == 0)
            return(search);

        free(search);
        i++;
    }
    ft_free_tab(cmd_path);
    return (0);
}



