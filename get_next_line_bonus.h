/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:52:02 by ajimenez          #+#    #+#             */
/*   Updated: 2021/09/24 14:45:02 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

/*
** libft functions
*/
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
/*
** gnl functions
*/
void	ft_strdel(char **ptr);
char	*ft_isnewline(const char *s);
char	*ft_out(int fd, char *line, char **aux, char *buff);
char	*tmp_join(int fd, char **saved, char *buff, ssize_t chars);
char	*get_line(int fd, char **aux, ssize_t i, char *ptr);
char	*get_next_line(int fd);

#endif
