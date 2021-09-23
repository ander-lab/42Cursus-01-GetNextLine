/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:46:20 by ajimenez          #+#    #+#             */
/*   Updated: 2021/09/23 15:37:19 by Alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strdel_gnl(char **line)
{
	if (line != NULL)
	{
		free(*line);
		*line = NULL;
	}
}

char	*ft_out(int fd, char *line, char **aux, char *buff)
{
	char	*ptr;
	size_t	len;

	free (buff);
	len = 0;
	while (aux[fd][len] != '\n')
		len++;
	line = ft_substr_gnl(aux[fd], 0, len + 1);
	ptr = ft_strdup_gnl(&(aux[fd][len + 1]));
	if (!ptr)
	{
		free(line);
		return (NULL);
	}
	free(aux[fd]);
	aux[fd] = ptr;
	return (line);
}

char	*output(char *line, char *ptr)
{
	ft_strdel_gnl(&line);
	free (ptr);
	return (0);
}

char	*get_line(int fd, char **aux, ssize_t chars, char *ptr)
{
	char	*line;
	char	*str;

	line = 0;
	while (chars > 0)
	{
		if (ft_isnewline_gnl(aux[fd]))
			return (ft_out(fd, line, aux, ptr));
		chars = read(fd, ptr, chars);
		ptr[chars] = '\0';
		if (!ft_isnewline_gnl(aux[fd]) && chars == 0)
		{
			line = ft_strdup_gnl(aux[fd]);
			ft_strdel_gnl(&aux[fd]);
			if (*line)
			{
				free (ptr);
				return (line);
			}
		}
		str = ft_strjoin_gnl(aux[fd], ptr);
		ft_strdel_gnl(&aux[fd]);
		aux[fd] = str;
		if (chars < 0)
			ft_strdel_gnl(&aux[fd]);
	}
	return (output(line, ptr));
}

char	*get_next_line(int fd)
{
	static char	*saved[4096];
	ssize_t		chars;
	char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 4096)
		return (NULL);
	if (!saved[fd])
		saved[fd] = ft_strdup_gnl("");
	if (!saved[fd])
		return (NULL);
	ptr = malloc(BUFFER_SIZE + 1);
	if (!ptr)
		return (0);
	chars = BUFFER_SIZE;
	return (get_line(fd, saved, chars, ptr));
}
