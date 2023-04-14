/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:14:33 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/07 14:12:38 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	here_or_not(char *av)
{
	if (av && (ft_strcmp(av, "here_doc")) == 0)
		return (6);
	else
		return (5);
}

void	ft_gestion(int	*pipe_fd, t_pipe *pipex)
{
	if (pipex->infile != -1)
		close (pipex->infile);
	pipex->infile = pipe_fd[0];
	close (pipe_fd[1]);
}

void	ft_gestion2(int	*pipe_fd)
{
	close(pipe_fd[1]);
	exit(EXIT_FAILURE);
}

void	ft_gestion3(t_pipe *pipex)
{
	close(pipex->outfile);
	close(pipex->infile);
}
