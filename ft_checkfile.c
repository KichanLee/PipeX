/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:26:12 by kichlee           #+#    #+#             */
/*   Updated: 2023/07/05 20:48:13 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_checkfile(char *infile, char *outfile, t_struct *t)
{
	t->fd1 = open(infile, O_RDONLY);
	if(t->fd1 < 0)
		perror("No such file or directory\n");
	t->fd2 = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if(t->fd2 < 0)
		ft_error("Can't Open Outfile\n");
}
