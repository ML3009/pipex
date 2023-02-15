/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:43:48 by ml                #+#    #+#             */
/*   Updated: 2023/02/15 14:47:32 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"


 /*La variable d'environnement PATH est utilisée pour localiser
    les commandes dans l'arborescence des répertoires SunOS.
    En définissant la variable PATH, vous créez un ensemble
    fixe de répertoires dans lesquels le système cherche
    systématiquement les fichiers à utiliser lorsque vous entrez
    le nom d'une commande. */
  //split  join path etc etc etc = env | def variable PATH |

/*void    ft_execute_cmd_1(t_vars *var)
{

    ft_printf ("Problem execute cmd1?\n");
    //var->path = ft_find_path_cmd_1(var);
   // if (!var->path)
    //{
      //  perror("\nvar->path\n");
        //ft_free_tab(var->cmd_1);
        //exit(EXIT_FAILURE);
    //}
    if (execve(var->path, var->cmd_1, var->envp) == -1)
    {
        perror("\nexecve\n");
        exit(EXIT_FAILURE);
    }
}*/

//trouver PATH dans l environnement du terminal (cf cmd env ou printenv PATH)
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
        join = ft_strjoin(cmd_path[i], "/"); // creation du chemin
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

/*void    ft_execute_cmd_2(t_vars *var)
{

    var->path = ft_find_path_cmd_2(var);
    if (!var->path)
    {
        perror("\nvar->path\n");
        ft_free_tab(var->cmd_2);
        exit(EXIT_FAILURE);
    }
    if (execve(var->path, var->cmd_2, var->envp) == -1)
    {
        perror("execve");
        exit(EXIT_FAILURE);
    }
}*/


