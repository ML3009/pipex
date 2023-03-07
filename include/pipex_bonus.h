/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:21:34 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/07 10:08:33 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <sys/types.h>
# include <sys/wait.h>
# include <assert.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_pipe
{
	int	pipe_fd[2];
	int	infile;
	int	outfile;
	int ac;

}	t_pipe;

void	ft_pipex_bonus(char *av, char **envp, t_pipe *pipex);
void	ft_first_dup(char **av, t_pipe *pipex);
void	ft_last_dup(char *av, char *cmd, char **envp, t_pipe *pipex);
char	*ft_find_path(char **cmd, char **envp);
char	**ft_path(char **envp);
void	ft_execute(char *av, char **envp);
void	ft_here_doc(char **av, t_pipe *pipex);
void	ft_put_here_doc(char *av, int *pipe_fd);
int		here_or_not(char *av);

#endif
