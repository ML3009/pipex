/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:36:32 by ml                #+#    #+#             */
/*   Updated: 2023/03/07 12:30:02 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_first_dup(char **av, t_pipe *pipex)
{
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile == -1)
		perror("open");
}

void	ft_pipex_bonus(char *av, char **envp, t_pipe *pipex)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe (pipe_fd) == -1)
		ft_perror("pipe");
	pid = fork();
	if (pid == -1)
		ft_perror("fork");
	if (pid == 0)
	{
		close (pipe_fd[0]);
		if (pipex->infile == -1)
			ft_gestion2(pipe_fd);
		if (dup2(pipex->infile, STDIN_FILENO) == -1)
			ft_perror("dup2");
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			ft_perror("dup2");
		close (pipex->infile);
		close (pipe_fd[1]);
		ft_execute(av, envp);
	}
	else
		ft_gestion(pipe_fd, pipex);
}

void	ft_last_dup(char *av, char *cmd, char **envp, t_pipe *pipex)
{
	pid_t	pid;

	pipex->outfile = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1)
	{
		close(pipex->infile);
		ft_perror("open");
	}
	pid = fork();
	if (pid == -1)
		ft_perror("fork");
	if (pid == 0)
	{
		if (dup2(pipex->infile, STDIN_FILENO) == -1)
			ft_perror("dup2");
		if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
			ft_perror("dup2");
		close(pipex->outfile);
		close(pipex->infile);
		ft_execute(cmd, envp);
	}
	else
		ft_gestion3(pipex);
}
