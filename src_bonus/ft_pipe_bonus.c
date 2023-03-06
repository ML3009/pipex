/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:36:32 by ml                #+#    #+#             */
/*   Updated: 2023/03/06 16:59:39 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_first_dup(char **av)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		ft_perror("open");
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
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			ft_perror("dup2");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
}

void	ft_last_dup(char **av, char *cmd, int ac, char **envp)
{
	int		outfile;
	pid_t	pid;

	outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		ft_perror("open");
	pid = fork();
	if (pid == -1)
		ft_perror("fork");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_perror("dup");
	close(outfile);
	if (pid == 0)
		ft_execute(cmd, envp);
}

void	ft_here_doc(char **av)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
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
		ft_put_here_doc(av[2], pipe_fd);
	else
	{
		if (dup2(pipe_fd[0], STDIN_FILENO))
			ft_perror("dup2");
		close(pipe_fd[1]);
		close(pipe_fd[0]);
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
