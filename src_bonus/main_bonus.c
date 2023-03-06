/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:55:38 by ml                #+#    #+#             */
/*   Updated: 2023/03/06 12:41:21 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	int	i;

	if (ac < here_or_not((av[1])))
	{
		ft_putstr_fd("Error : wrong number of argument\n", 2);
		return (0);
	}
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		i = 3;
		ft_here_doc(av);
	}
	else
	{
		i = 2;
		ft_first_dup(av);
	}
	while (i < ac - 2)
		ft_pipex_bonus(av[i++], envp);
	ft_last_dup(av, av[i], ac, envp);
	while (wait(NULL) != -1)
		;
	return (0);
}
