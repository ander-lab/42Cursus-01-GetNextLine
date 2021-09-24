/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:49:19 by ajimenez          #+#    #+#             */
/*   Updated: 2021/09/24 14:32:07 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l] != '\0')
		++l;
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	int		i;
	int		aux_s2;

	if (!s1 || !s2)
		return (0);
	sjoin = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!sjoin)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		sjoin[i] = s1[i];
		i++;
	}
	aux_s2 = 0;
	while (s2[aux_s2] != '\0')
	{
		sjoin[i] = s2[aux_s2];
		i++;
		aux_s2++;
	}
	sjoin[i] = '\0';
	return (sjoin);
}

char	*ft_isnewline(const char *s)
{
	char	c;

	c = '\n';
	while (*s != '\0')
	{
		if ((unsigned char)c == (unsigned char)*s)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			aux_start;
	size_t			cont_substr;
	size_t			l;

	if (!s)
		return (0);
	l = ft_strlen(s);
	aux_start = start;
	cont_substr = 0;
	while (cont_substr < len && s[aux_start++])
		cont_substr++;
	substr = (char *)malloc(cont_substr + 1);
	if (!substr)
		return (0);
	aux_start = start;
	cont_substr = 0;
	while (cont_substr < len && aux_start < l)
		substr[cont_substr++] = s[aux_start++];
	substr[cont_substr] = '\0';
	return (substr);
}

char	*ft_strdup(char *s1)
{
	char	*s_dup;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1) + 1;
	s_dup = (char *)malloc(sizeof(char) * len);
	if (!s_dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		((unsigned char *)s_dup)[i] = ((unsigned char *)s1)[i];
		i++;
	}
	s_dup[i - 1] = 0;
	return (s_dup);
}
