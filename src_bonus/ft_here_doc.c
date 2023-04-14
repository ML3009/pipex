/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:33:57 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/07 10:34:50 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

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
