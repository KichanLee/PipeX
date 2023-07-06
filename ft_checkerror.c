/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:47:56 by kichlee           #+#    #+#             */
/*   Updated: 2023/07/05 21:12:59 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit(1);
}

void    ft_checkerror(int ac, char **av, char **evnp)
{
	if(ac != 5)
		ft_error("Argument count is not properly\n");
    if(!av[1] || !av[4])
		ft_error("Argument value is not properly\n");
    // if(!evnp || *evnp)
	// 	ft_error("Can't find path properly\n");
}