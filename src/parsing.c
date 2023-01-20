/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:13:39 by ml                #+#    #+#             */
/*   Updated: 2023/01/20 10:18:49 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *PATH_from_envp;
char *mypaths;
char **mycmdargs;

//retrieve the line PATH from envp
PATH_from_envp = ft_substr(envp ...); 
mypaths = ft_split(PATH_from_envp, ":");
mycmdargs = ft_split(av[2], " ")

// in your child or parent process 

int i; 
char *cmd;

i = 0;
while(mypaths[i++])
{
    cmd = ft_strjoin(mypaths[i], envp); // protect strjoin
    execve(cmd, mycmdargs, envp); // if excve suceeds, it exits
        perror("Error"); // add perror to debug
        free(cmd) // if execve failsm we free and we try a new path    
}
return (EXIT_FAILURE);