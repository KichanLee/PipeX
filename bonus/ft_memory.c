/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 03:00:35 by kichlee           #+#    #+#             */
/*   Updated: 2023/07/07 03:00:39 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t c, size_t s)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = malloc(c * s);
	if (!ptr)
		return (0);
	while (i < (c * s))
	{
		((unsigned char *)ptr)[i] = 0;
		++i;
	}
	return (ptr);
}