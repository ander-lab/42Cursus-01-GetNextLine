/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:52:02 by ajimenez          #+#    #+#             */
/*   Updated: 2021/09/23 15:16:25 by Alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strdup_gnl(const char *s1);
void	ft_strdel_gnl(char **ptr);
char	*ft_isnewline_gnl(const char *s);
//char	*ft_out(int fd, char *line, char **aux);
char	*ft_out(int fd, char *line, char **aux, char *buff);
char	*output(char *line, char *ptr);
//char	*get_line(int fd, char **aux, char *ptr, ssize_t chars);
char	*get_line(int fd, char **aux, ssize_t i, char *ptr);
char	*get_next_line(int fd);


#endif
