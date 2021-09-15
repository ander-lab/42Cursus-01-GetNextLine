/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:46:20 by ajimenez          #+#    #+#             */
/*   Updated: 2021/09/15 12:51:41 by ajimenez         ###   ########.fr       */
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

char	*tmp_free(char **saved, int fd, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(saved[fd], buff);
	free(saved[fd]);
	saved[fd] = tmp;
	return (saved[fd]);
}

char	*get_line(char **saved, int fd, size_t len)
{
	char	*line;
	char	*tmp;

	line = NULL;
	if (saved[fd][len] == '\n')
	{
		line = ft_substr(saved[fd], 0, len + 1);
		tmp = ft_strdup(&(saved[fd][len + 1]));
		free(saved[fd]);
		saved[fd] = tmp;
	}
	else
	{
		line = ft_strdup(saved[fd]);
		free(saved[fd]);
		saved[fd] = NULL;
	}
	return (line);
}

char	*check_boom(char **saved, int fd)
{
	size_t	aux;

	aux = 0;
	if (saved[fd] == '\0' || saved[fd][aux] == '\0')
	{
		free(saved[fd]);
		saved[fd] = NULL;
		return (0);
	}
	while (saved[fd][aux] != '\0' && saved[fd][aux] != '\n')
		aux++;
	return (get_line(saved, fd, aux));
}

char	*get_next_line(int fd)
{
	ssize_t		chars;
	static char	*saved[32768];
//	char		buff[1];
	char		*buff;

	buff = malloc(sizeof(char) + BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	if (fd < 0 || read(fd, buff, 0) == -1)
		return (0);
	chars = read(fd, buff, BUFFER_SIZE);
	if (chars == -1)
		return (0);
	buff[chars] = '\0';
	while (chars)
	{
		if (!saved[fd])
			saved[fd] = ft_calloc(sizeof(char), 1);
		tmp_free(saved, fd, buff);
		if (ft_strchr(buff, '\n'))
			break ;
		chars = read(fd, buff, BUFFER_SIZE);
		if (chars == -1)
			return (0);
		buff[chars] = '\0';
	}
	free (buff);
	return (check_boom(saved, (const int)fd));
}
