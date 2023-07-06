/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:30:47 by kichlee           #+#    #+#             */
/*   Updated: 2023/07/07 01:05:52 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*plus_slash(char *str)
{
	char	*str_slash;
	int		i;

	str_slash = (char *)malloc(ft_strlen_a(str) + 2);
	i = 1;
	if (!str_slash)
		ft_error("plus_slash error!\n");
	str_slash[0] = '/';
	while (*str)
	{
		str_slash[i] = *str;
		++i;
		++str;
	}
	str_slash[i] = '\0';
	return (str_slash);
}

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
		i++;
	}
	return (NULL);
}

char	*ft_check_access_file(char **av, char **str)
{
	int		i;
	char	*check_file;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		tmp = plus_slash(av[0]);
		check_file = ft_strjoin(str[i], tmp);
		free(tmp);
		if (!check_file)
			return (NULL);
		if (access(check_file, F_OK | X_OK) == 0)
			return (check_file);
		free(check_file);
		++i;
	}
	return (NULL);
}
