/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:29:59 by ml                #+#    #+#             */
/*   Updated: 2023/02/15 14:29:19 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void    ft_init(t_vars *var, int ac, char **av)
{
    var->ac = ac;
    var->av = av;
    var->cmd_1 = ft_split(av[2], ' ');
    var->cmd_2 = ft_split(av[3], ' ');
	 int i = 0;
	 while(var->cmd_1[i])
    {
        ft_printf("%s\n", var->cmd_1[i]);
        i++;
    }
    int j = 0;
    while(var->cmd_2[j])
    {
        ft_printf("%s\n", var->cmd_2[j]);
        j++;
    }
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
