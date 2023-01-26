/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:54:32 by ml                #+#    #+#             */
/*   Updated: 2023/01/26 09:24:45 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../lib_dil/libft.h"

typedef struct s_vars
{
    int ac;
    char    **av;
    char    **envp;
    char    **av_cmd1;
    char    **av_cmd2;
    int cmd1;
    int cmd1_v2;
    int cmd2;
    int cmd2_v2;
    int infile;
    int outfile;
    int pipe_fd[2];
}   t_vars;

void    ft_init(t_vars *var, int ac, char **av, char **envp);
void    ft_open_files(t_vars *var);
void    ft_create_pipe(t_vars *var);
void    ft_create_fork(t_vars *var);
void    ft_create_dup2_cmd1(t_vars *var);
void    ft_create_dup2_cmd2(t_vars *var);
