/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:07:21 by kichlee           #+#    #+#             */
/*   Updated: 2023/07/06 22:32:41 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void leaks()
{
	system("leaks a.out");
}


int	main(int ac, char **av, char **envp)
{
	char		*str;
	t_struct	t;
	int			status;

	// atexit(leaks);
	ft_checkerror(ac, av, envp);
	ft_checkfile(av[1], av[4], &t);
	str = ft_check_path(envp);
	if (!str)
		ft_error("Path error!");
	str += 5;
	t.s_envp = ft_split(str, ':');
	// free(str);
	ft_preprocess_av(av[2], av[3], &t);
	int i = 0;

	ft_getpipe(&t, envp);
	while (t.s_envp[i])
	{
		free(t.s_envp[i]);
		++i;
	}
	return (0);
}
