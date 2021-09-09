/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:46:20 by ajimenez          #+#    #+#             */
/*   Updated: 2021/09/09 15:29:50 by ajimenez         ###   ########.fr       */
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

char	*get_line(char **saved, int fd, int len);


char	*check_boom(char **saved, int fd)
{
	int	aux;

	aux = 0;
	if (!saved[fd])
		return(0);
	while (!saved[fd][aux])
		aux++;
	return (get_line(saved, fd, aux));
}

char	*get_next_line(int fd)
{
	ssize_t	chars;
	char	*saved[FILE_N];
	char	*tmp;
	char	*buff[BUFFER_SIZE + 1];

	if (fd == -1 || read(fd, buff, BUFFER_SIZE) == -1)
		return  (0);
	chars = read(fd, buff, BUFFER_SIZE);
	while (chars)
	{
		if (!saved[fd])
			saved[fd] = ft_calloc(sizeof(buff));
		tmp = ft_strjoin(saved[fd], buff);
		free(saved[fd]);
		saved[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
		chars = read(fd, buff, BUFFER_SIZE);
	}
	return (0);
}
