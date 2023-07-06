/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:08:14 by kichlee           #+#    #+#             */
/*   Updated: 2023/07/06 22:25:59 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_childone(t_struct *t, char **envp)
{
	t->pid = fork();
	if (t->pid == 0)
	{
		close(t->px[0]);
		if (dup2(t->fd1, 0) < 0 || dup2(t->px[1], 1) < 0)
		{
			if (t->fd1 < 0)
				exit(1);
			ft_error("dup2 failed!");
		}
		if (execve(t->path1, t->parsing_av1, envp) == -1)
			ft_error("execve failed!");
		close(t->px[1]);
	}
}

void	ft_childtwo(t_struct *t, char **envp)
{
	t->pid_two = fork();
	if (t->pid_two == 0)
	{
		close(t->px[1]);
		if (dup2(t->px[0], 0) < 0 || dup2(t->fd2, 1) < 0)
			ft_error("dup2 failed!");
		if (execve(t->path2, t->parsing_av2, envp) == -1)
			ft_error("execve failed!");
		close(t->px[0]);
	}
}

void	ft_getpipe(t_struct *t, char **envp)
{
	pipe(t->px);
	ft_childone(t, envp);
	ft_childtwo(t, envp);
	close(t->px[0]);
	close(t->px[1]);
	close(t->fd1);
	close(t->fd2);
	waitpid(-1, 0, 0);
	waitpid(-1, 0, 0);
}
