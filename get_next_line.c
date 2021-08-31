/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:49:59 by ajimenez          #+#    #+#             */
/*   Updated: 2021/08/31 15:10:58 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_save(char *saved)
{
	if (saved)
	{
		free (saved);
		saved = 0;
	}
}

char	*get_line(char	*saved)
{
	int		nline;
	int		index;
	char	*line;

	index = 0;
	while (saved[index] != '\0' && nline == 0)
	{
		if (saved[index] == '\n')
			nline = 1;
		index++;
	}
	line = malloc(sizeof(char) * index + 1);
	if (!line)
		return (0);
	ft_strcpy(line, saved);
	return (0);
}

char	*get_next_line(int fd)
{
}
