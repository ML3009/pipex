/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:55:38 by ml                #+#    #+#             */
/*   Updated: 2023/03/07 10:08:36 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	int	i;
	t_pipe	pipex;

	if (ac < here_or_not((av[1])))
	{
		ft_putstr_fd("Error : wrong number of argument\n", 2);
		return (0);
	}
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		i = 3;
		ft_here_doc(av, &pipex);
	}
	else
	{
		i = 2;
		ft_first_dup(av, &pipex);
	}
	while (i < ac - 2)
		ft_pipex_bonus(av[i++], envp, &pipex);
	ft_last_dup(av[ac - 1], av[i], envp, &pipex);
	while (wait(NULL) != -1)
		;
	return (0);
}
