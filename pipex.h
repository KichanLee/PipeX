/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichan <kichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:56:43 by kichan            #+#    #+#             */
/*   Updated: 2023/06/29 17:26:11 by kichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

typedef struct s_stuct
{
    char    **s_envp;
} t_struct;



// header file
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// split.c
char	**ft_split(char const *s, char c);

// ft_strnstr.c
size_t	ft_strlen_a(const char *ch);
char	*ft_strnstr(const char *s1, const char *s2, size_t l);

// ft_strncmp.c
int	ft_strncmp(const char *s1, const char *s2, size_t t);

//ft_strrchr.c
char	*ft_strrchr(const char *s, int c);

// ft_strjoin.c
char	*ft_strjoin(char const *s1, char const *s2);
#endif 