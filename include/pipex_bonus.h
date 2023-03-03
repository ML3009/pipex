/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:21:34 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/03 11:29:23 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <sys/types.h>
# include <sys/wait.h>
# include <assert.h>
# include <fcntl.h>
# include "../libft/libft.h"

void	ft_pipex_bonus(char *av, char **envp);
void	ft_first_dup(char **av);
void	ft_last_dup(int ac, char **av);
char	*ft_find_path(char **cmd, char **envp);
void	ft_execute(char *av, char **envp);

#endif
