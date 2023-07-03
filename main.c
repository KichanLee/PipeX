/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:30:40 by kichlee           #+#    #+#             */
/*   Updated: 2023/07/03 21:13:41 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **envp)
{ 
	char		*str;
	t_struct	t;

	str = ft_check_path(envp) + 5;
	t.s_envp = ft_split(str, ':');
	pipe(t.px);
	t.path_one = ft_check_access_one(av, str);
	t.path_two = ft_check_access_one(av, str);

	if(!(t.path_one && t.path_one))
	{
		printf("erorr!\n");
		printf("%s\n", t.path_one);
		printf("%s\n", t.path_two);
	}
	t.pid = fork();
	if(t.pid == -1)
		printf("Failed to fork!\n");
	
	else if(t.pid == 0)
	{
		execve(t.path_one, &(av[2]), envp);
	}
	else
	{
		printf("parent process!\n");
	}
}
