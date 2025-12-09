/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:46:23 by toespino          #+#    #+#             */
/*   Updated: 2025/12/09 18:18:36 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strlcpy_until(char *stash)
{
	int		i;
	char	*out;

	if (!stash)
		return (NULL);
	i = 0;
	out = malloc(sizeof(char) * (ft_strlen(stash) + 1));
	if (!out)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
	{
		out[i] = stash[i];
		i++;
	}
	out[i] = '\n';
	out[i + 1] = '\0';
	return (out);
}

char	*ft_strlcpy_since(char *stash)
{
	int		i;
	int		j;
	char	*out;

	if (!stash)
		return (NULL);
	i = 0;
	out = malloc(sizeof(char) * (ft_strlen(stash) + 1));
	if (!out)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	i++;
	j = 0;
	while (stash[i + j])
	{
		out[j] = stash[i + j];
		j++;
	}
	out[j] = '\0';
	return (out);
}

char	*ft_process(char **stash)
{
	char	*out;
	char	*temp;
	char	*line;

	if (!stash || !*stash)
		return (NULL);
	if (!**stash || !stash)
	{
		free(*stash);
		return (NULL);
	}
	out = ft_strlcpy_until(*stash);
	line = ft_strlcpy_since(*stash);
	temp = *stash;
	free(temp);
	*stash = line;
	return (out);
}

char	*get_next_line(int fd)
{
	int			red_bytes;
	static char	*stash[1024];
	char		*buffer;
	char		*out;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	red_bytes = 1;
	*buffer = 0;
	while (ft_strchr(buffer, '\n') == 0 && red_bytes > 0)
	{
		red_bytes = read(fd, buffer, BUFFER_SIZE);
		if (red_bytes < 0)
		{
			buffer = ft_free(buffer, stash[fd]);
			return (NULL);
		}
		buffer[red_bytes] = '\0';
		stash[fd] = ft_strjoin(stash[fd], buffer);
	}
	out = ft_process(&stash[fd]);
	free(buffer);
	return (out);
}
