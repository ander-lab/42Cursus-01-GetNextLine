/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:46:20 by ajimenez          #+#    #+#             */
/*   Updated: 2021/09/12 00:26:54 by Alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	char	*s_dup;
	size_t	i;

	s_dup = (char *)malloc(ft_strlen(s1) + 1);
	if (!s_dup && !s1)
		return (0);
	i = 0;
	while (i < ft_strlen(s1) + 1)
	{
		((unsigned char *)s_dup)[i] = ((unsigned char *)s1)[i];
		i++;
	}
	s_dup[i] = 0;
	return (s_dup);
}

char	*get_line(char **saved, int fd, size_t len)
{
	char	*line;
	char	*tmp;

	line = NULL;
	if (saved[fd][len] != '\n')
	{
		line = ft_strdup(saved[fd]);
		free(saved[fd]);
		saved[fd] = NULL;
	}
	else
	{
		//line = ft_substr(saved[fd], 0, len + 1);
		line = ft_strdup(&(saved[fd][len + 1]));
		tmp = ft_strdup(&(saved[fd][len + 1]));
		free(saved[fd]);
		saved[fd] = tmp;
	}
	return(line);
}

char	*check_boom(char **saved, int fd)
{
	size_t	aux;

	aux = 0;
	if (!saved[fd])
		return(0);
	while (!saved[fd][aux] && saved[fd][aux] != '\n')
		aux++;
	return (get_line(saved, fd, aux));
}

char	*get_next_line(int fd)
{
	ssize_t		chars;
	static char	*saved[FILE_N];
	char		*tmp;
	char 		*buff[BUFFER_SIZE + 1];
	char		*check;

	if (fd == -1 || read(fd, buff, BUFFER_SIZE) == -1)
		return  (0);
	chars = read(fd, buff, BUFFER_SIZE);
	while (chars)
	{
		if (!saved[fd])
			saved[fd] = ft_calloc(sizeof(char), BUFFER_SIZE);
		tmp = ft_strjoin(saved[fd], buff);
		free(saved[fd]);
		saved[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
		chars = read(fd, buff, BUFFER_SIZE);
	}
	check = check_boom(saved, fd);
	return (check);
}
