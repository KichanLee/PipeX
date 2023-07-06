/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpath_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 03:28:56 by kichlee           #+#    #+#             */
/*   Updated: 2023/07/07 03:34:45 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_check_path(char **envp)
{
	int		i;
	char	*path_check;

	i = 0;
	while (envp[i])
	{
		path_check = ft_strnstr(envp[i], "PATH", ft_strlen_a(envp[i]));
		if (path_check)
			return (path_check);
        free(path_check);
		i++;
	}
	return (NULL);
}