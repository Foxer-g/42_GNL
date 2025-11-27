/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:11:08 by toespino          #+#    #+#             */
/*   Updated: 2025/11/27 19:10:38 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*out;

	if (!s)
		return (NULL);
	out = malloc(ft_strlen((char *)s) + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (s[i])
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

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

char	*ft_create_buffer(char *buffer, int *i, int fd)
{
	char		*temp;

	temp = NULL;
	if (!*buffer)
	{
		*i = read(fd, buffer, BUFFER_SIZE);
		if (*i == 0)
			buffer = NULL;
	}
	else
		*i = ft_strlen(buffer);
	while (!ft_have_end_line(buffer) && *i)
	{
		*i = read(fd, buffer, BUFFER_SIZE);
		buffer[*i] = '\0';
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
	temp = NULL;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_create_buffer(temp, &i, fd);
	if (!buffer)
		buffer = malloc(ft_strlen(temp));
	if (!buffer)
		return (NULL);
	out = ft_strcpy_until(temp);
	if (i != 0)
	{
		buffer = ft_strcpy_since(temp);
		free(temp);
	}
	else
		free(temp);
	return (out);
}
