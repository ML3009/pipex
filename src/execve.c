/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:37:54 by ml                #+#    #+#             */
/*   Updated: 2023/01/20 10:13:24 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int execve(const char *path char *const argv[], char *envp[])
{
    // path = the path to our command
    // argv[] = the args the cmd needs for ex : ls -l 
    // => use split 
    // envp = the environmental variable = type env in terminal and
    // find PATH. use split with ":" as a delimiter    
}

