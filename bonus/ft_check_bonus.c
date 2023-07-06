/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerror_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 01:31:37 by kichlee           #+#    #+#             */
/*   Updated: 2023/07/07 03:26:16 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void ft_error(char *str)
{
    perror(str);
    exit(1);
}

void    ft_init_pipe(int ac, char **av, char **envp, t_struct *t)
{
    int i;
    int j;

    i = 0;
    while (i < ac - 4)
    {
        t->pipes[i] = (int *)calloc(sizeof(int), 2);
        if (t->pipes[i] == NULL)
        {
            j = 0;
            while (j < i)
            {
                free(t->pipes[j]);
                ++j;
            }
            free(t->pipes);
            ft_error("Memory allocation Failed");
        }
        ++i;
    }
}

void    ft_init_pid(int ac, char **av, char **envp, t_struct *t)
{
    int i;

    i = 0;
    t->pid = (pid_t *) ft_calloc(sizeof(pid_t), (ac - 3));
    if (t->pid == NULL)
        ft_error("Memory allocation Failed");
}

void ft_checkerror(int ac, char **av, char **envp, t_struct *t)
{
    if (!envp || !*envp)
        ft_error("Can't Find Path\n");
    if (ft_strcmp(av[1], "here_doc") == 0)
        ft_heredoc();
    t->infile_fd = open(av[1], O_RDONLY);
    if (t->infile_fd < 0)
    {
        write(1, &av[1], ft_strlen_a(av[1]));
        write(1, ": No such file or directory\n", 28);
    }
    t->outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (t->outfile_fd < 0)
        ft_error("Can't Open Outfile\n");
    ft_init_pipe(ac, av, envp, &t);
    ft_init_pid(ac, av, envp, &t);
}