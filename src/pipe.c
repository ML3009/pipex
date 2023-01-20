/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:08:37 by ml                #+#    #+#             */
/*   Updated: 2023/01/20 10:25:19 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    pipex(int fd1, int fd2, char *cmd1, char *cmd2)
{
    int end[2];
    int status;
    pid_t child1;
    pid_t child2;

    pipe(end);
    child1 = fork();
    if (child1 < 0)
        return (perror("Fork : "));
    if (child == 0)
        child_one(fd1, cmd1);
    child2 = fork();
    if (child2 < 0)
        return (perror("Fork : "));
    if (child2 == 0)
        child_two(fd2, cmd2);
    close(end[0])
    close(end[1])
    waitpid(child1, &status, 0); // supervising the children
    waitpid(child2, &status, 0) // while they finish their tasks
}
   
void    pipex_parent(int fd1, int fd2)
 {
    int end[2];    
    pid_t parent;

    pipe(end);
    parent = fork();
    if (parent < 0)
        return (perror("Fork : "));
    if (!parent) // if parent return 0 we r n child p.
        child_process(fd1, cmd1);
    else    
        parent_process(fd2, cmd2);


}
