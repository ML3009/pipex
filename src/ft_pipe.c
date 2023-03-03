/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:36:32 by ml                #+#    #+#             */
/*   Updated: 2023/03/03 13:12:42 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_pipex(char **av, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe (pipe_fd) == -1)
		ft_perror("pipe");
	pid1 = fork();
	if (pid1 == -1)
		ft_perror("fork");
	if (pid1 == 0)
	{
		ft_first_cmd(av, pipe_fd, envp);
	}
	pid2 = fork();
	if (pid2 == -1)
		ft_perror("fork");
	if (pid2 == 0)
	{
		ft_scd_cmd(av, pipe_fd, envp);
	}
	else
		ft_gestion(pipe_fd, pid1, pid2);
}

void	ft_gestion(int	*pipe_fd, pid_t pid1, pid_t pid2)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
