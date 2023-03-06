/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:55:38 by ml                #+#    #+#             */
/*   Updated: 2023/03/06 11:30:49 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **envp)
{
	if (ac != 5)
		ft_putstr_fd("\nError : wrong numbers of arguments\n", 2);
	else
		ft_pipex(av, envp);
	return (0);
}
