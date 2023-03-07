/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:36:32 by ml                #+#    #+#             */
/*   Updated: 2023/03/07 10:10:28 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_first_dup(char **av, t_pipe *pipex)
{
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile == -1)
		perror("open");
	//if (dup2(infile, STDIN_FILENO) == -1)
	//	ft_perror("dup2");
	//close(infile);
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
			exit(EXIT_FAILURE);
		if (dup2(pipex->infile, STDIN_FILENO) == -1)
			ft_perror("dup2");
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			ft_perror("dup2");
		close (pipex->infile);
		//close (pipex->pipe_fd[0]);
		close (pipe_fd[1]);
		ft_execute(av, envp);
	}
	else
	{
		//if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		//	ft_perror("dup2");
		close(pipex->infile);
		pipex->infile = pipe_fd[0];
		close(pipe_fd[1]);
		//close(pipex->pipe_fd[0]);
	}
}

void	ft_last_dup(char *av, char *cmd, char **envp, t_pipe *pipex)
{
	pid_t	pid;

	pipex->outfile = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1)
		ft_perror("open");
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
	{
		close(pipex->outfile);
		close(pipex->infile);
	}
}

void	ft_here_doc(char **av, t_pipe *pipex)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		ft_perror("pipe");
	pid = fork();
	if (pid == -1)
		ft_perror("fork");
	if (pid == 0)
		ft_put_here_doc(av[2], pipe_fd);
	else
	{
		pipex->infile = pipe_fd[0];
		if (dup2(pipex->infile, STDIN_FILENO))
			ft_perror("dup2");
		close(pipe_fd[1]);
		waitpid(pid, NULL, 0);
	}
}

void	ft_put_here_doc(char *av, int *pipe_fd)
{
	char	*line;

	while (1)
	{
		write(1, "pipe heredoc> ", 15);
		line = get_next_line(1);
		if ((ft_strncmp(line, av, ft_strlen(av)) == 0) \
				&& line[ft_strlen(av)] == '\n')
		{
			free(line);
			close(pipe_fd[1]);
			close(pipe_fd[0]);
			exit(EXIT_SUCCESS);
		}
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
	}
}
