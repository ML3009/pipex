/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:36:32 by ml                #+#    #+#             */
/*   Updated: 2023/03/05 21:28:50 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_first_dup(int infile)
{
	if (dup2(infile, STDIN_FILENO) == -1)
		ft_perror("dup2");
	close(infile);
}

void	ft_pipex_bonus(char *av, char **envp)
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
		close(pipe_fd[0]);
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			ft_perror("dup2");
		close(pipe_fd[1]);
		ft_execute(av, envp);
	}
	else
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		waitpid(pid, NULL, 0);
	}
}

void	ft_last_dup(int outfile)
{
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_perror("dup2");
	close(outfile);
}

void	ft_here_doc(char **av)
{
	int	pipe_fd[2];
	pid_t	pid;
	if (pipe (pipe_fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		ft_put_here_doc(av[2], pipe_fd);
	}
	else
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		waitpid(pid, NULL, 0);
	}
}

void	ft_put_here_doc(char *av, int *pipe_fd)
{
	char	*line;
	while(1)
	{
		write(1, "pipe heredoc> ", 15);
		line = get_next_line(1);
		if(ft_strncmp(line, av, ft_strlen(av)) == 0)
		{
			close(pipe_fd[1]);
			close(pipe_fd[0]);
			exit(EXIT_SUCCESS);
		}
		write(pipe_fd[1], line, ft_strlen(line));
	}
}
