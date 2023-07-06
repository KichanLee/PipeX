/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:56:43 by kichan            #+#    #+#             */
/*   Updated: 2023/07/07 03:34:05 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define HEREDOC "7DB7AD6E-A68E-4A97-B988-61DB560FEEB9"
/*
** Header files
*/
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct s_struct
{
    int     **pipes;
    pid_t   *pid;
    int     infile_fd;
    int     outfile_fd;
    
}   t_struct;


// ft_string.h
int     ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen_a(const char *ch);
char	*ft_strnstr(const char *s1, const char *s2, size_t l);
char	*ft_strjoin(char const *s1, char const *s2);



// ft_memory.c
void	*ft_calloc(size_t c, size_t s);

// ft_checkerror_bonus.c

void ft_checkerror(int ac, char **av, char **envp, t_struct *t);

// ft_check_path.c
char	*ft_check_path(char **envp);



#endif
