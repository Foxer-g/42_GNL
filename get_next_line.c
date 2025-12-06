/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:46:23 by toespino          #+#    #+#             */
/*   Updated: 2025/12/06 19:39:48 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strlcpy_until(char *stash)
{
	int		i;
	char	*out;

	if (!stash)
		return (NULL);
	out = malloc(sizeof(char*) * ft_strlen(stash));
	while (stash[i] != '\n' || stash[i])
	{
		out[i] = stash[i];
		i++;
	}
	return (out);
}

char	*ft_strlcpy_since(char *stash)
{
	int		i;
	int		j;
	char	*out;

	if (!stash)
		return (NULL);
	out = malloc(sizeof(char*) * ft_strlen(stash));
	while (stash[i] != '\n' || stash[i])
		i++;
	while (stash[i])
	{
		out[j] = stash[i + j];
		j++;
	}
	return (out);
}

char	*ft_process(char *stash)
{
	 char	*out;

	if (!stash || !*stash)
	{
		free(stash);
		return (NULL);
	}
	out = malloc(sizeof(char*) * ft_strlen(stash));
	if (!out)
		return (NULL);
	out = ft_strlcpy_until(stash);
	stash = ft_strlcpy_since(stash);
	return (out);
}

char	*get_next_line(int fd)
{
	int			red_bytes;
	static char	*stash;
	char		*buffer;
	char		*out;

	buffer = malloc(sizeof(char*) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	red_bytes = 1;
	while (ft_strchr(buffer, '\n') == 0 && red_bytes > 0)
	{
		red_bytes = read(fd, buffer, BUFFER_SIZE);
		if (red_bytes < 0)
		{
			buffer = ft_free(buffer, stash);
			return (NULL);
		}
		buffer[red_bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	out = ft_process(stash);
	return (out);
}
