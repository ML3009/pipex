/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:54:32 by ml                #+#    #+#             */
/*   Updated: 2023/01/24 19:49:06 by ml               ###   ########.fr       */
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
    int infile;
    int outfile;
    int pipe_end[2];
}   t_vars;

void    ft_init(t_vars *vars, int ac, char **av, char **envp);
void    ft_open_files(t_vars *vars);
