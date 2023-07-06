/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:30:40 by kichlee           #+#    #+#             */
/*   Updated: 2023/07/06 15:02:07 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **envp)
{ 
	char		*str;
	t_struct	t;
	int			status;
	
	int i  = 0;

	ft_checkerror(ac, av, envp);
	ft_checkfile(av[1], av[4], &t);
	str = ft_check_path(envp);
	if(!str)
		ft_error("str error!");
	str += 5;
	t.s_envp = ft_split(str, ':');
	ft_preprocess_av(av[2], av[3], &t);

	pipe(t.px);





	t.pid = fork();
	
	int p = 0;

	if(t.pid == 0)
	{
		close(t.px[0]);
		dup2(t.fd1, 0); 
		dup2(t.px[1], 1);
		execve(t.path1, t.parsing_av1, envp);
	}
	close(t.px[1]);
	int pid2 = fork();
	
	if(pid2 == 0)
	{
		close(t.px[1]);
		dup2(t.px[0], 0);
		dup2(t.fd2, 1);
		execve(t.path2, t.parsing_av2, envp);
	}
	close(t.px[0]);
	close(t.px[1]);

	waitpid(-1, 0, 0);
	waitpid(-1, 0, 0);

	close(t.fd1);
	close(t.fd2);
	return (0);
}
