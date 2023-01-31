/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:29:59 by ml                #+#    #+#             */
/*   Updated: 2023/01/31 11:11:47 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void    ft_init(t_vars *var, int ac, char **av, char **envp)
{
    var->ac = ac;
    var->av = av;
    var->envp = envp;
    var->path = NULL;
    var->cmd_1 = ft_split(av[2], ' ');
    var->cmd_2 = ft_split(av[3], ' ');
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free (tab);
}