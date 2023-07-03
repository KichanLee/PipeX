/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichan <kichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:19:17 by kichan            #+#    #+#             */
/*   Updated: 2023/06/29 17:37:26 by kichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_access(char *str1, char *str2)
{
	if (access(str1, F_OK | R_OK | W_OK | X_OK	!= -1) || access(str2, F_OK | R_OK | W_OK | X_OK != -1))
	{
		perror("not access to file");
		exit(1);
	}
}
// ./pipex file1 cmd1 cmd2 file2
// file1 cmd1 | cmd2 > file2
void ft_error(int ac)
{
	if(ac != 5)
		write(1, "erorr\n", 6);
	exit(1);
}


int main(int ac, char **av, char **envp)
{
	int		pipefd[2];
	int		status;
	pid_t	pid;
	pid_t	wpid; 
	
	// ft_error(ac);
	// ft_check_access(av[1], av[4]);
	// if (pipe(pipefd) == -1)
	// {
	// 	perror("pipe error!");
	// 	ft_error(1);
	// }
	// fork 함수 예외처리 방법은?
	pid = fork();
	if(pid == -1)
		ft_error(pid);
	else if(pid == 0)
	{	
		// ./pipex file1 cmd1 cmd2 file2
		// ' ' split 함수 사용해서 공백을 기준으로 나누어준다음 분리해준다.
		char **str;
		// 56569073027341
	
		// str = ft_split(av, ' ');
		// 
		char *cmd[] = {"/bin/ps", "aux", NULL};
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		int ste = execve(cmd[0], cmd, NULL);
		if(ste == -1)
		{
			printf("error!\n");
			exit(1);
		}
	}
	else
	{
		close(pipefd[1]);
		wpid = waitpid(pid, &status, WNOHANG);
		if(wpid == -1)
			printf("waitpid error");
		else
		{
			dup2(pipefd[0], 0);
			char line[255];
			while (fgets(line, sizeof(line), stdin) != 0)
				printf("%s", line);
		}
	}
    return 0;
}
