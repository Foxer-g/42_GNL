/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:11:08 by toespino          #+#    #+#             */
/*   Updated: 2025/11/17 20:00:02 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*out;
	int			i;
	static char	*buffer;
	char		*temp;

	out =  NULL;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!*buffer)
		i = read(fd, buffer, BUFFER_SIZE);
	else
		i = ft_strlen(buffer);
	while (!ft_have_end_line() && i != 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, temp);
	}
	out = ft_strlcpy_until(buffer);
	if (i != 0)
	{
		temp = buffer;
		free(buffer);
		buffer = ft_strlcpy_since(temp);
	}
	else
		free(buffer);
	return (out);
}
