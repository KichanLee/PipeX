/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:25:16 by kichlee           #+#    #+#             */
/*   Updated: 2023/07/07 03:33:52 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		++s1;
		++s2;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		t_len;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	t_len = ft_strlen_a(s1) + ft_strlen_a(s2);
	str = malloc(t_len + 1);
	if (!str)
		return (0);
	while (i < ft_strlen_a(s1))
	{
		str[i] = s1[i];
		++i;
	}
	while (i < t_len)
	{
		str[i] = s2[j];
		++i;
		++j;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen_a(const char *ch)
{
	size_t	i;

	i = 0;
	while (ch[i])
		++i;
	return (i);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t l)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen_a(s2);
	if (!*s2)
		return ((char *)s1);
	while (s1[i] && i < l)
	{
		if (s1[i] == s2[j])
			j++;
		else if (s1[i] != s2[j])
		{	
			i -= j;
			j = 0;
		}
		++i;
		if (len == j)
			return ((char *)&s1[i - len]);
	}
	return (0);
}