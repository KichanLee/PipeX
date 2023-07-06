/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:00:33 by kichlee           #+#    #+#             */
/*   Updated: 2023/07/06 15:00:17 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_preprocess_av(char *str1, char *str2, t_struct *t)
{
    t->parsing_av1 = ft_parsing_av(str1);
    t->parsing_av2 = ft_parsing_av(str2);
    t->path1 = ft_check_access_file(t->parsing_av1, t->s_envp);
    t->path2 = ft_check_access_file(t->parsing_av2, t->s_envp);
}