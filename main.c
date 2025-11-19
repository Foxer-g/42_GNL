/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:07:59 by toespino          #+#    #+#             */
/*   Updated: 2025/11/19 16:50:54 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	i = 18;
	line = get_next_line(fd);
	while (i > 0)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i--;
	}
	free(line);
	close(fd);
	return (0);
}
