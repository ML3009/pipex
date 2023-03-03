/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:54:32 by ml                #+#    #+#             */
/*   Updated: 2023/03/03 12:54:58 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include<sys/types.h>
# include<sys/wait.h>
# include<assert.h>
# include<fcntl.h>
# include "../libft/libft.h"

void	ft_pipex(char **av, char **envp);
void	ft_first_cmd(char **av, int *pipe_fd, char **envp);
void	ft_scd_cmd(char **av, int *pipe_fd, char **envp);
char	*ft_find_path(char **cmd, char **envp);
void	ft_execute(char *av, char **envp);
void	ft_gestion(int	*pipe_fd, pid_t pid1, pid_t pid2);

#endif
