/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:07:21 by kichlee           #+#    #+#             */
/*   Updated: 2023/07/07 19:28:01 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	leaks(void)
{
	system("leaks a.out");
}

int	main(int ac, char **av, char **envp)
{
	char		*str;
	t_struct	t;
	int			status;
	int			i;

	i = 0;
	atexit(leaks);
	ft_checkerror(ac, av, envp);
	ft_checkfile(av[1], av[4], &t);
	str = ft_check_path(envp);
	if (!str)
		ft_error("Path error!");
	str += 5;
	t.s_envp = ft_split(str, ':');
	ft_preprocess_av(av[2], av[3], &t);
	ft_getpipe(&t, envp);
	while (t.s_envp[i])
	{
		free(t.s_envp[i]);
		++i;
	}
	free(t.path1);
	free(t.path2);
	free(t.s_envp);
	return (0);
}
