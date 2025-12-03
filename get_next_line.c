/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:11:08 by toespino          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/12/02 19:30:54 by toespino         ###   ########.fr       */
=======
/*   Updated: 2025/11/24 21:15:01 by toespino         ###   ########.fr       */
>>>>>>> parent of 5cabdf9 (IT NOW WORK (but valgrind said))
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*out;

	len = ft_strlen((char *)s);
	out = malloc(len + 1);
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

<<<<<<< HEAD
=======
char	*ft_create_buffer(char *buffer, int *i, int fd)
{
	char		*temp;

	temp = NULL;
	if (!*buffer)
		*i = read(fd, buffer, BUFFER_SIZE);
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

>>>>>>> parent of 5cabdf9 (IT NOW WORK (but valgrind said))
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
	temp = malloc((size_t)BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	if (!*buffer)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i == 0)
			buffer = NULL;
	}
	else
		i = ft_strlen(buffer);
	while (!ft_have_end_line(buffer) && i)
	{
		i = read(fd, temp, BUFFER_SIZE);
		temp[i] = '\0';
		buffer = ft_strjoin_f(buffer, temp);
	}
	out = ft_strcpy_until(temp);
	if (!buffer)
		buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	out = ft_strcpy_until(buffer);
	if (i != 0)
	{
		temp = ft_strdup(buffer);
		free(buffer);
		buffer = ft_strcpy_since(temp);
	}
	else
		free(buffer);
	return (out);
}
