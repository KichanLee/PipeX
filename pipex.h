/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:56:43 by kichan            #+#    #+#             */
/*   Updated: 2023/07/04 16:42:13 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H



// header file
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// struct
typedef struct s_stuct
{
    int     px[2];
    pid_t   pid;
    char    **s_envp;
    char    *path_one;
    char    *path_two;
    char    **sp_av;
    
} t_struct;

// split.c
char	**ft_split(char const *s, char c);

// ft_parsing.c
size_t	ft_strlen_a(const char *ch);
char	*ft_strnstr(const char *s1, const char *s2, size_t l);
int     ft_strncmp(const char *s1, const char *s2, size_t t);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

//ft_checkpath.c
char	*plus_slash(char *str);
char	*ft_check_path(char **envp);
char	*ft_check_access_one(char **av, char **str, int num);

#endif 