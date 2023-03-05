/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:55:38 by ml                #+#    #+#             */
/*   Updated: 2023/03/05 21:21:07 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	outfile;
	int	infile;

	if (ac < 5)
		ft_putstr_fd("\nError : wrong numbers of arguments\n", 2);
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		i = 3;
		ft_here_doc(av);
		outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile == -1)
			ft_perror("open");

	}
	else
	{
		i = 2;
		infile = open(av[1], O_RDONLY);
		if (infile == -1)
			ft_perror("open");
		outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile == -1)
			ft_perror("open");
		ft_first_dup(infile);

	}
	while (i < ac - 2)
		ft_pipex_bonus(av[i++], envp);
	ft_last_dup(outfile);
	ft_execute(av[i], envp);
	return (0);
}
