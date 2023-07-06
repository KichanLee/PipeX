/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:56:43 by kichan            #+#    #+#             */
/*   Updated: 2023/07/05 17:07:56 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H



// header file
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

// struct
typedef struct s_stuct
{
    int     px[2];
    pid_t   pid;
    char    **s_envp;
	char	*path1;
	char	*path2;
    char    **parsing_av1;
    char    **parsing_av2;
    char    **sp_av;
    int     fd1;
    int     fd2;
    char    *infile;
    char    *outfile;
    
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
char	*ft_check_access_file(char **av, char **str);

//ft_checkfile.c
void	ft_checkfile(char *infile, char *outfile, t_struct *t);
char	**ft_parsing_av(char *str);

//ft_checkerror.c
void    ft_checkerror(int ac, char **av, char **evnp);
void	ft_error(char *str);

//ft_preprocess.c
void    ft_preprocess_av(char *str1, char *str2, t_struct *t);

#endif 