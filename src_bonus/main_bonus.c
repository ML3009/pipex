/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:55:38 by ml                #+#    #+#             */
/*   Updated: 2023/03/04 11:12:44 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	int	i;

	i = 2;
	if (ac < 5)
		ft_putstr_fd("\nError : wrong numbers of arguments\n", 2);
	else
	{
		ft_first_dup(av);
		while (i < ac - 2)
			ft_pipex_bonus(av[i++], envp);
		ft_last_dup(ac, av);
		ft_execute(av[i], envp);
	}
	return (0);
}
