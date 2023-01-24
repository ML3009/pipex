/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:35:13 by ml                #+#    #+#             */
/*   Updated: 2023/01/20 09:38:27 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

parent_process(fd2, cmd2)
{
int status;

waitpid(-1, &status, 0);
dup2(f2, STDOUT_FILENO) // fd2 is the stdout
dup2(end[0], STDINT_FILENO) // end[0] is the stdin
close(end[1]);
close(fd2) 
// execve function for each possible path
exit(EXIT_FAILURE);
}
