/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:30:40 by kichlee           #+#    #+#             */
/*   Updated: 2023/07/04 17:37:39 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_parsing_av(char *str)
{
	char	**re;

	re = ft_split(str, ' ');
	if(!re)
		return(NULL);
	return (re);
}	


int main(int ac, char **av, char **envp)
{ 
	char		*str;
	t_struct	t;
	char		**parsing_av1;
	char		**parsing_av2;
	char		*path1;
	char		*path2;
	int			status;
	
	str = ft_check_path(envp) + 5;
	t.s_envp = ft_split(str, ':');
	parsing_av1 = ft_parsing_av(av[1]);
	parsing_av2 = ft_parsing_av(av[2]);
	path1 = ft_check_access_one(parsing_av1, t.s_envp, 2);
	path2 = ft_check_access_one(parsing_av2, t.s_envp, 2);

	pipe(t.px);
	t.pid = fork();
		
	if(t.pid == 0)
	{
		close(t.px[0]);
		dup2(t.px[1], 1);
		close(t.px[1]);
		printf("child process!\n");
		execve(path1, parsing_av1, envp);
	}

	int pid2 = fork();

	if(pid2 == 0)
	{
		close(t.px[1]);
		dup2(t.px[0], 0);
		close(t.px[0]);
		execve(path2, parsing_av2, envp);
	}
	close(t.px[0]);
	close(t.px[1]);
	waitpid(t.pid, NULL, 0);
	waitpid(pid2, NULL, 0);

	return (0);
}
