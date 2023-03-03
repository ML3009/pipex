/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:43:48 by ml                #+#    #+#             */
/*   Updated: 2023/03/03 11:27:40 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	*ft_find_path(char **cmd, char **envp)
{
	int		i;
	char	*join;
	char	*search;
	char	**cmd_path;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4))
		i++;
	cmd_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (cmd_path[i])
	{
		join = ft_strjoin(cmd_path[i], "/");
		search = ft_strjoin(join, cmd[0]);
		if (access(search, F_OK) == 0)
			return (search);
		free(search);
		i++;
	}
	free(cmd_path);
	return (0);
}

void	ft_execute(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	if (ft_strchr(cmd[0], '/') != NULL)
		path = cmd[0];
	else
		path = ft_find_path(cmd, envp);
	if (path)
	{
		if (execve(path, cmd, envp) == -1)
		{
			ft_free_tab(cmd);
			ft_perror("execve");
		}
	}
	else
	{
		ft_free_tab(cmd);
		ft_perror("path");
	}
	ft_free_tab(cmd);
}

/*void	ft_here_doc(char **av)
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
		close(pipe_fd[0]);
		ft_put_here_doc(av[2], pipe_fd);
		//free(line);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	ft_put_here_doc(char *av, int pipe_fd[2])
{
	char	*ret;
	size_t	len;

	len = ft_strlen(av);
	while (1)
	{

		ft_printf("pipe heredoc> ");
		ft_printf("%s\n", av);
		ret = get_next_line(STDIN_FILENO);
		ft_printf("%s\n", av);
		//ft_putstr_fd(line, pipe_fd[1]);
		//ft_printf("%s\n", line);
		if (!ret)
		{
			close(pipe_fd[1]);
			close(pipe_fd[0]);
			exit(EXIT_FAILURE);
		}
		if (ret[len] == '\n' && av && !ft_strncmp(ret, av, len) == 0)
		{
			//free(ret);
			close(pipe_fd[1]);
			close(pipe_fd[0]);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(ret, pipe_fd[1]);
		free(ret);
		//free(ret);
		//	break;
		ft_printf("%s\n", av[2]);
	}

}

	// my first cmd take in STDIN = total of gnl;
	// pipe

*/

//./pipex "/dev/random" cat cat "/dev/stdin" ???????
