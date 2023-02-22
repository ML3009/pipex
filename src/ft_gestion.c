/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:29:59 by ml                #+#    #+#             */
/*   Updated: 2023/02/22 17:33:50 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_init(t_vars *var, int ac, char **av, char **envp)
{
	var->ac = ac;
	var->av = av;
	var->envp = envp;
	var->cmd_1 = ft_split(av[2], ' ');
	var->cmd_2 = ft_split(av[3], ' ');
}
//cpter nbr de cmd -  nb cmd x  2 - execute child
