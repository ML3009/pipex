/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:21:34 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/05 21:22:45 by mvautrot         ###   ########.fr       */
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
}	t_pipe;

void	ft_pipex_bonus(char *av, char **envp);
void	ft_first_dup(int infile);
void	ft_last_dup(int outfile);
char	*ft_find_path(char **cmd, char **envp);
void	ft_execute(char *av, char **envp);
void	ft_here_doc(char **av);
void	ft_put_here_doc(char *av, int *pipe_fd);

#endif
