/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:43:48 by ml                #+#    #+#             */
/*   Updated: 2023/03/06 16:54:05 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	**ft_path(char **envp)
{
	int	i;
	char	**cmd_path;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH", envp[i], 4))
		{
			cmd_path = ft_split(envp[i] + 5, ':');
			return(cmd_path);
		}
		i++;
	}
	return(NULL);
}

char	*ft_find_path(char **cmd, char **envp)
{
	int		i;
	char	*join;
	char	*search;
	char	**cmd_path;

	cmd_path = ft_path(envp);
	if (cmd_path == NULL)
	{
		ft_free_tab(cmd);
		ft_putstr_fd("wrong path\n", 2);
		exit(EXIT_FAILURE);
	}
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

int	here_or_not(char *av)
{
	if (av && (ft_strcmp(av, "here_doc")) == 0)
		return (6);
	else
		return (5);
}
