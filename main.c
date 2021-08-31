/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:49:11 by ajimenez          #+#    #+#             */
/*   Updated: 2021/08/31 10:17:02 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		num;

	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	if (fd == -1)
		printf("Error al abrir file");
	else
	{
		num = 1;
		line = get_next_line(fd);
		while (line)
		{
			printf("%i- %s", num, line);
			line = get_next_line(fd);
			num++;
		}
		printf("%i- %s", num, line);
	}
	close(fd);
	return (0);
}
