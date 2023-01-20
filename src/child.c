/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:30:26 by ml                #+#    #+#             */
/*   Updated: 2023/01/20 09:38:55 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//add protection if dup2() < 0
// dup2 close stdin, fd1 become the new stdin
child_process(fd1, cmd1)
{
dup2(fd1, STDIN_FILENO); // we want fd1 to be execve()input
dup2(end[1], STDOUT_FILENO); // we want end[1] to be execve()stdout
close (end[0]) // always close the end of the pipe you don't use.
close(fd1); 
// execve function for each possible path
exit(EXIT_FAILURE);
}