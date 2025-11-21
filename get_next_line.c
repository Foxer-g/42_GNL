/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:11:08 by toespino          #+#    #+#             */
/*   Updated: 2025/11/21 18:29:32 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_have_end_line(char *buffer)
{
	int	i;
	int	res;
	int	len;

	i = 0;
	res = 0;
	len = ft_strlen(buffer);
	while (i < len)
	{
		if (buffer[i] == '\n')
		{
			res = 1;
			break ;
		}
		i++;
	}
	return (res);
}

char	*ft_create_buffer(char *buffer, int i, int fd)
{
	char		*temp;

	temp = NULL;
	if (!*buffer)
		i = read(fd, buffer, BUFFER_SIZE);
	else
		i = ft_strlen(buffer);
	while (!ft_have_end_line(buffer) && i != 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		buffer[i] = '\0';
		buffer = ft_strjoin_f(buffer, temp);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*out;
	int			i;
	static char	*buffer;
	char		*temp;

	out = NULL;
	i = 0;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	temp = ft_create_buffer(buffer, i, fd);
	out = ft_strcpy_until(buffer);
	if (i != 0)
	{
		temp = buffer;
		free(buffer);
		buffer = ft_strcpy_since(temp);
	}
	else
		free(buffer);
	return (out);
}
