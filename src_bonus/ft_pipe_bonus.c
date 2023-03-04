/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:36:32 by ml                #+#    #+#             */
/*   Updated: 2023/03/04 14:04:18 by mvautrot         ###   ########.fr       */
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
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		waitpid(pid, NULL, 0);
	}
}

void	ft_last_dup(int ac, char **av)
{
	int	outfile;

	outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		ft_perror("open");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_perror("dup2");
	close(outfile);
}
