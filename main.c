/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:14:50 by ajimenez          #+#    #+#             */
/*   Updated: 2021/09/15 16:42:14 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

void leak (void)
{
	system("leaks a.out");
}

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
			free(line);
			line = get_next_line(fd);
			num++;
		}
		printf("%i- %s", num, line);
	}
	close(fd);
	atexit(leak);
	return (0);
}
